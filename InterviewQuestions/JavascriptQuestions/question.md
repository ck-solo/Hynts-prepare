# JavaScript Interview Questions & Answers

## Q1. What is Event Bubbling in JavaScript?

**Answer:**
Event bubbling is the process in which an event starts at the **target element** and then propagates upward through its parent elements in the DOM tree.

For example, if you click a button inside a `<div>`, the event can first trigger on the button, then bubble up to the `<div>`, its parent, and eventually the document.

### Example

```js
const parent = document.querySelector("#parent");
const child = document.querySelector("#child");

parent.addEventListener("click", () => {
  console.log("Parent clicked");
});

child.addEventListener("click", () => {
  console.log("Child clicked");
});
```

If the child is clicked, the output will be:

```text
Child clicked
Parent clicked
```

You can stop event propagation using:

```js
event.stopPropagation();
```

---

## Q2. Explain `bind()`, `call()`, and `apply()` methods in JavaScript.

**Answer:**
`call()`, `apply()`, and `bind()` are methods used to explicitly control the value of `this` when calling a function.

### `call()`

`call()` immediately invokes a function with a specified `this` value. Arguments are passed individually.

```js
function greet(city) {
  console.log(`Hello ${this.name} from ${city}`);
}

const user = {
  name: "John"
};

greet.call(user, "Delhi");
```

### `apply()`

`apply()` works similarly to `call()`, but arguments are passed as an array (or array-like value).

```js
greet.apply(user, ["Delhi"]);
```

### `bind()`

`bind()` does **not** immediately execute the function. Instead, it returns a new function with the specified `this` value and optionally preset arguments.

```js
const newGreet = greet.bind(user, "Delhi");

newGreet();
```

### Difference

| Method    | Invokes Immediately? | Arguments                               |
| --------- | -------------------- | --------------------------------------- |
| `call()`  | Yes                  | Individual arguments                    |
| `apply()` | Yes                  | Array/array-like of arguments           |
| `bind()`  | No                   | Individual arguments, optionally preset |

---

## Q3. What is the difference between `map()` and `forEach()`?

**Answer:**
Both `map()` and `forEach()` iterate over array elements, but they are used for different purposes.

### `map()`

`map()` creates and returns a **new array** containing the results of the callback function.

```js
const numbers = [1, 2, 3];

const doubled = numbers.map(num => num * 2);

console.log(doubled);
// [2, 4, 6]
```

The original array is not modified by `map()` itself.

### `forEach()`

`forEach()` executes a callback for each element but does not create a new array. Its return value is `undefined`.

```js
const numbers = [1, 2, 3];

numbers.forEach(num => {
  console.log(num * 2);
});
```

### Difference

| `map()`                                             | `forEach()`                           |
| --------------------------------------------------- | ------------------------------------- |
| Returns a new array                                 | Returns `undefined`                   |
| Used for transforming data                          | Used mainly for side effects          |
| Can be chained with other array methods             | Does not return an array for chaining |
| Callback result becomes an element in the new array | Callback result is ignored            |

**Use `map()` when you need a transformed array and `forEach()` when you simply need to perform an action for each element.**

---

## Q4. What is Hoisting in JavaScript?

**Answer:**
**Hoisting** refers to the behavior where JavaScript makes declarations available within their scope before the actual line where the declaration appears is executed.

However, different declarations behave differently.

### Function Declaration

Function declarations can be called before their declaration in the source code.

```js
sayHello();

function sayHello() {
  console.log("Hello");
}
```

This works because the function declaration is available before execution reaches its declaration.

### `var`

Variables declared with `var` are hoisted and initialized with `undefined`.

```js
console.log(name); // undefined

var name = "John";
```

Conceptually, this behaves roughly like:

```js
var name;

console.log(name);

name = "John";
```

### `let` and `const`

`let` and `const` are also hoisted in the sense that their bindings are created for the scope, but they are **not initialized** until execution reaches their declaration.

The period before initialization is called the **Temporal Dead Zone (TDZ)**.

```js
console.log(name); // ReferenceError

let name = "John";
```

### Summary

| Declaration          | Hoisted? | Initialized before declaration? |
| -------------------- | -------- | ------------------------------- |
| Function declaration | Yes      | Yes                             |
| `var`                | Yes      | `undefined`                     |
| `let`                | Yes      | No — TDZ                        |
| `const`              | Yes      | No — TDZ                        |

---

## Q5. What is the difference between `bind()` and `call()`?

**Answer:**
Both `bind()` and `call()` allow us to explicitly set the `this` value of a function, but they behave differently.

### `call()`

`call()` **immediately invokes** the function.

```js
function greet(city) {
  console.log(`${this.name} lives in ${city}`);
}

const user = {
  name: "John"
};

greet.call(user, "Delhi");
```

### `bind()`

`bind()` **does not immediately invoke** the function. It returns a new function with the specified `this` value.

```js
const greetUser = greet.bind(user, "Delhi");

greetUser();
```

### Key Difference

```text
call()  → Sets this → Executes immediately
bind()  → Sets this → Returns a new function
```

**Use `call()` when you want immediate execution and `bind()` when you want to create a reusable function with a specific `this` context.**

---

## Q6. What is the `this` keyword in JavaScript?

**Answer:**
The `this` keyword refers to the value associated with the **current function invocation**. Its value depends primarily on **how the function is called**, rather than where the function was defined.

### 1. Object Method

When a regular function is called as an object method, `this` generally refers to the object before the dot.

```js
const user = {
  name: "John",

  greet() {
    console.log(this.name);
  }
};

user.greet();
// John
```

### 2. Regular Function

In a regular function, the value of `this` depends on the execution mode.

In strict mode:

```js
"use strict";

function showThis() {
  console.log(this);
}

showThis();
// undefined
```

In non-strict browser code, a standalone function call can have the global object as `this`.

### 3. Arrow Function

Arrow functions do not have their own `this`. They inherit `this` from their surrounding lexical scope.

```js
const user = {
  name: "John",

  greet() {
    const showName = () => {
      console.log(this.name);
    };

    showName();
  }
};

user.greet();
// John
```

### 4. Explicit Binding

`call()`, `apply()`, and `bind()` can explicitly set `this` for regular functions.

```js
function greet() {
  console.log(this.name);
}

const user = {
  name: "John"
};

greet.call(user);
// John
```

### Important Point

A good way to remember `this` is:

> **For regular functions, `this` is primarily determined by how the function is called. Arrow functions inherit `this` from their surrounding scope.**

---

## Q7. What is a Callback Function?

**Answer:**
A **callback function** is a function that is passed as an argument to another function so that it can be called later.

Callbacks can be used for both synchronous and asynchronous operations.

### Synchronous Example

```js
function calculate(a, b, callback) {
  const result = a + b;
  callback(result);
}

calculate(10, 20, result => {
  console.log(result);
});
```

### Asynchronous Example

```js
setTimeout(() => {
  console.log("Executed after 2 seconds");
}, 2000);
```

Here, the function passed to `setTimeout()` is a callback.

Callbacks are commonly used for:

* Event handlers
* Timers
* Asynchronous operations
* Array methods such as `map()`, `filter()`, and `forEach()`

When many asynchronous callbacks become deeply nested, the code can become difficult to maintain. This is commonly known as **callback hell**.

---

## Q8. What is Callback Hell?

**Answer:**
**Callback hell**, also known as the **Pyramid of Doom**, occurs when multiple callbacks are nested inside one another, especially when several asynchronous operations need to happen sequentially.

### Example

```js
getUser(userId, user => {
  getOrders(user, orders => {
    getFirstOrder(orders, order => {
      getPayment(order, payment => {
        console.log(payment);
      });
    });
  });
});
```

As the number of operations increases, the code becomes:

* Difficult to read
* Difficult to maintain
* Difficult to debug
* Difficult to handle errors consistently

### How to Avoid Callback Hell

Modern JavaScript commonly uses **Promises** and **async/await**.

Using Promises:

```js
getUser(userId)
  .then(user => getOrders(user))
  .then(orders => getFirstOrder(orders))
  .then(order => getPayment(order))
  .then(payment => console.log(payment))
  .catch(error => console.error(error));
```

Using `async/await`:

```js
async function processOrder() {
  try {
    const user = await getUser(userId);
    const orders = await getOrders(user);
    const order = await getFirstOrder(orders);
    const payment = await getPayment(order);

    console.log(payment);
  } catch (error) {
    console.error(error);
  }
}
```

---

## Q9. What is the difference between Callback, Promise, and Async/Await?

**Answer:**
Callbacks, Promises, and `async/await` are different approaches for handling asynchronous operations in JavaScript.

### Callback

A callback is a function passed to another function to be executed later.

```js
setTimeout(() => {
  console.log("Done");
}, 1000);
```

Callbacks are simple but can become difficult to manage when many asynchronous operations are nested.

---

### Promise

A **Promise** represents the eventual completion or failure of an asynchronous operation.

A Promise can be:

* **Pending**
* **Fulfilled**
* **Rejected**

Example:

```js
fetch("/api/users")
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error(error));
```

Promises make sequential asynchronous operations easier to organize.

---

### Async/Await

`async/await` is syntax built on top of Promises that allows asynchronous code to be written in a more sequential-looking style.

```js
async function getUsers() {
  try {
    const response = await fetch("/api/users");
    const data = await response.json();

    console.log(data);
  } catch (error) {
    console.error(error);
  }
}
```

### Comparison

| Callback                            | Promise                       | Async/Await                   |
| ----------------------------------- | ----------------------------- | ----------------------------- |
| Function passed to another function | Represents an eventual result | Syntax built on Promises      |
| Can become deeply nested            | Supports chaining             | Usually easier to read        |
| Error handling can be awkward       | `.catch()` handles rejection  | `try/catch` can handle errors |
| Older/common async pattern          | Modern async pattern          | Modern syntax for Promises    |

### Simple Relationship

```text
Callbacks
    ↓
Promises
    ↓
Async/Await
```

This does **not** mean callbacks are replaced internally by async/await. Rather, `async/await` provides a cleaner syntax for working with Promises.

---

## Q10. Explain Async/Await and its Advantages.

**Answer:**
`async/await` is JavaScript syntax used to work with **Promises** in a more readable, sequential-looking way.

### `async`

The `async` keyword makes a function return a Promise.

```js
async function hello() {
  return "Hello";
}
```

This is effectively a Promise-based result:

```js
hello().then(result => {
  console.log(result);
});
```

### `await`

The `await` keyword can be used inside an `async` function to wait for a Promise to settle.

```js
async function getData() {
  const response = await fetch("/api/users");
  const data = await response.json();

  console.log(data);
}
```

`await` pauses the execution of that **async function** until the awaited Promise settles. It does not block the JavaScript thread or browser UI.

### Error Handling

Errors from awaited rejected Promises can be handled using `try/catch`.

```js
async function getData() {
  try {
    const response = await fetch("/api/users");
    const data = await response.json();

    console.log(data);
  } catch (error) {
    console.error("Error:", error);
  }
}
```

### Advantages of Async/Await

#### 1. Better Readability

Asynchronous code can look similar to sequential code.

#### 2. Easier Error Handling

`try/catch` provides a familiar way to handle errors.

#### 3. Reduces Promise Chain Nesting

Instead of:

```js
getData()
  .then(data => processData(data))
  .then(result => saveData(result))
  .catch(error => console.error(error));
```

You can write:

```js
async function process() {
  try {
    const data = await getData();
    const result = await processData(data);
    await saveData(result);
  } catch (error) {
    console.error(error);
  }
}
```

#### 4. Easier Debugging

Sequential-looking code can be easier to follow when debugging.

#### 5. Works with Promise-Based APIs

`async/await` works directly with APIs that return Promises.

### Important Point

`async/await` does **not** make asynchronous operations synchronous or block the JavaScript runtime. It provides a cleaner way to write and manage Promise-based asynchronous code.

---

# Quick Revision

| #      | Topic                              | Key Point                                                                        |
| ------ | ---------------------------------- | -------------------------------------------------------------------------------- |
| **1**  | Event Bubbling                     | Event propagates from the target element upward through its ancestors            |
| **2**  | `call()`, `apply()`, `bind()`      | Methods for controlling `this`                                                   |
| **3**  | `map()` vs `forEach()`             | `map()` returns a new array; `forEach()` returns `undefined`                     |
| **4**  | Hoisting                           | Declarations are processed before their execution in their scope                 |
| **5**  | `bind()` vs `call()`               | `call()` executes immediately; `bind()` returns a new function                   |
| **6**  | `this`                             | Depends on how a regular function is called; arrows inherit lexical `this`       |
| **7**  | Callback                           | Function passed to another function for later execution                          |
| **8**  | Callback Hell                      | Deeply nested callbacks that make code difficult to maintain                     |
| **9**  | Callback vs Promise vs Async/Await | Different approaches/syntax for asynchronous programming                         |
| **10** | Async/Await                        | Promise-based syntax for writing asynchronous code in a sequential-looking style |
