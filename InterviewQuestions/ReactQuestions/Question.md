# React.js – Important Questions and Answers

## 1. What is React, and what are its main features?

**React** is an open-source JavaScript library developed by **Meta (Facebook)** for building user interfaces, especially **single-page applications (SPAs)**.

React allows developers to create reusable UI components and efficiently update the user interface when data changes.

### Main Features of React

1. **Component-Based Architecture**

   * React applications are built using reusable components.
   * Each component manages its own structure and behavior.

2. **JSX**

   * JSX allows us to write HTML-like syntax inside JavaScript.
   * It makes UI code easier to read and write.

3. **Virtual DOM**

   * React uses a Virtual DOM to efficiently update the real DOM.
   * Only the parts of the UI that need to change are updated.

4. **One-Way Data Flow**

   * Data generally flows from parent components to child components through props.
   * This makes applications easier to understand and debug.

5. **Reusable Components**

   * Components can be reused in different parts of an application.
   * This reduces code duplication.

6. **Declarative UI**

   * Developers describe **what the UI should look like** for a particular state.
   * React handles updating the DOM to match that state.

7. **Large Ecosystem**

   * React has a large ecosystem of libraries and tools for routing, state management, forms, testing, and more.

---

## 2. What is JSX and how does it work?

**JSX (JavaScript XML)** is a syntax extension for JavaScript that allows us to write HTML-like code inside JavaScript.

### Example

```jsx
const element = <h1>Hello, World!</h1>;
```

Although JSX looks like HTML, it is not actually HTML. It is transformed into JavaScript that creates React elements.

For example:

```jsx
const element = <h1>Hello, World!</h1>;
```

is conceptually transformed into something similar to:

```js
const element = React.createElement("h1", null, "Hello, World!");
```

Modern React projects typically use a JSX transform that can handle JSX without manually importing `React` just for JSX.

### JSX Expressions

JavaScript expressions can be written inside JSX using `{}`.

```jsx
const name = "John";

const element = <h1>Hello, {name}!</h1>;
```

Output:

```text
Hello, John!
```

### Benefits of JSX

* Makes UI code easier to read.
* Allows JavaScript logic and UI markup to be written together.
* Supports JavaScript expressions.
* Helps React create elements in a structured way.

---

## 3. Explain the concept of the Virtual DOM in React.

The **Virtual DOM** is an in-memory representation of the UI.

Instead of directly manipulating the browser's DOM every time something changes, React maintains a representation of the UI and uses it to determine what needs to change in the real DOM.

### How it works

Suppose the UI initially looks like:

```jsx
<h1>Hello</h1>
```

Later it changes to:

```jsx
<h1>Hello John</h1>
```

React creates a new representation of the UI and compares it with the previous one.

It determines that only the text inside the `<h1>` has changed and updates the necessary part of the browser DOM.

This comparison process is commonly referred to as **reconciliation**.

### Important Point

The Virtual DOM is **not necessarily faster than the DOM for every operation**. Its main benefit is that React can efficiently determine and manage the DOM updates required by changes in application state.

---

## 4. How does Virtual DOM in React work? What are its benefits and downsides?

### How the Virtual DOM works

The general process is:

```text
State/Props Change
       ↓
React renders the component
       ↓
New React element tree
       ↓
Reconciliation
       ↓
React determines required DOM changes
       ↓
Browser DOM is updated
```

For example:

```jsx
function App() {
  return <h1>Hello</h1>;
}
```

If the component later renders:

```jsx
function App() {
  return <h1>Hello John</h1>;
}
```

React compares the new result with the previous result and applies the required update to the DOM.

### Benefits

#### 1. Efficient DOM Updates

React can avoid unnecessary DOM operations by determining which parts need to change.

#### 2. Declarative Programming

Developers describe the desired UI instead of manually manipulating DOM elements.

#### 3. Better Developer Experience

React's component model and reconciliation system make complex UIs easier to manage.

#### 4. Predictable UI Updates

UI changes are driven by changes in state and props.

### Downsides

#### 1. Additional Memory Usage

React keeps an in-memory representation of the UI.

#### 2. Reconciliation Has a Cost

React still has to render and reconcile component trees when updates occur.

#### 3. Not Always Faster

For simple applications or carefully optimized direct DOM operations, React's abstraction can sometimes add overhead rather than improve performance.

#### 4. Poor Component Design Can Cause Extra Work

Unnecessary re-renders or poorly structured components can reduce performance.

---

## 5. What is the difference between React Node, React Element, and React Component?

These terms are related but have different meanings.

### React Node

A **React node** is anything that React can render.

Examples include:

```jsx
"Hello"
```

```jsx
123
```

```jsx
<div>Hello</div>
```

```jsx
[<span>A</span>, <span>B</span>]
```

`null`, `undefined`, and booleans can also appear in React children and are treated as rendering nothing.

So, **React Node is the broadest concept**.

---

### React Element

A **React element** is an object describing what React should render.

For example:

```jsx
const element = <h1>Hello</h1>;
```

The variable `element` represents a React element.

It describes things such as:

* The element type
* Its props
* Its children

A React element is **not the actual DOM element**.

---

### React Component

A **React component** is a reusable piece of UI logic that returns React elements/nodes.

Example:

```jsx
function Greeting() {
  return <h1>Hello!</h1>;
}
```

Here, `Greeting` is a React component.

It can be used as:

```jsx
<Greeting />
```

### Simple Difference

| Concept             | Meaning                                      |
| ------------------- | -------------------------------------------- |
| **React Node**      | Anything React can render                    |
| **React Element**   | Description of something React should render |
| **React Component** | Reusable function/class that produces UI     |

A useful way to remember it:

```text
Component → produces → React Element/Nodes → React renders → UI
```

---

## 6. What are React Fragments used for?

**React Fragments** allow us to group multiple elements without adding an unnecessary DOM element.

Normally, a component must return a single root element.

For example:

```jsx
return (
  <div>
    <h1>Hello</h1>
    <p>Welcome!</p>
  </div>
);
```

The `<div>` is added to the DOM.

With a Fragment:

```jsx
return (
  <>
    <h1>Hello</h1>
    <p>Welcome!</p>
  </>
);
```

React groups the elements without adding an extra DOM node.

### Explicit Fragment Syntax

```jsx
return (
  <React.Fragment>
    <h1>Hello</h1>
    <p>Welcome!</p>
  </React.Fragment>
);
```

### Why use Fragments?

* Avoid unnecessary DOM elements.
* Keep the DOM structure clean.
* Useful when working with tables, lists, and layouts where an extra wrapper could cause problems.

---

## 7. What is the purpose of the `key` prop in React?

The **`key` prop** helps React identify individual elements in a list.

Example:

```jsx
const users = [
  { id: 1, name: "John" },
  { id: 2, name: "Sarah" },
  { id: 3, name: "Mike" }
];

function Users() {
  return (
    <ul>
      {users.map(user => (
        <li key={user.id}>
          {user.name}
        </li>
      ))}
    </ul>
  );
}
```

Here:

```jsx
key={user.id}
```

gives each list item a stable identity.

### Why are keys important?

Suppose the list changes:

```text
Before:
A
B
C

After:
X
A
B
C
```

Keys help React understand that:

```text
X → new item
A → existing item
B → existing item
C → existing item
```

This helps React correctly reconcile the list.

### Good Keys

A key should ideally be:

* Unique among siblings.
* Stable across renders.
* Based on the identity of the item.

A database ID is often a good choice:

```jsx
key={user.id}
```

---

## 8. What is the consequence of using array indices as keys in React?

Using an array index as a key can cause problems when the list can be **reordered, inserted into, or deleted from**.

Example:

```jsx
{items.map((item, index) => (
  <Item key={index} value={item} />
))}
```

Suppose the original list is:

```text
0 → A
1 → B
2 → C
```

Now we insert `X` at the beginning:

```text
0 → X
1 → A
2 → B
3 → C
```

The keys of existing items change.

React may then associate component instances with the wrong data.

### Possible Problems

* Incorrect component state associated with list items.
* Unexpected input values.
* Incorrect focus behavior.
* Unnecessary DOM updates.
* Bugs when items are reordered or deleted.

### When is an index key acceptable?

An index can be acceptable when the list:

* Never changes.
* Is never reordered.
* Does not have items inserted or removed.
* Does not rely on item-specific component state.

For dynamic lists, prefer a stable ID:

```jsx
key={item.id}
```

---

## 9. What are props in React? How are they different from state?

### Props

**Props (properties)** are values passed from a parent component to a child component.

Example:

```jsx
function User({ name }) {
  return <h1>Hello, {name}</h1>;
}

function App() {
  return <User name="John" />;
}
```

Here:

```jsx
name="John"
```

is a prop.

Props are **read-only from the receiving component's perspective**. A child should not directly modify its props.

---

### State

**State** is data managed by a component that can change over time.

Example:

```jsx
import { useState } from "react";

function Counter() {
  const [count, setCount] = useState(0);

  return (
    <button onClick={() => setCount(count + 1)}>
      {count}
    </button>
  );
}
```

Here:

```jsx
count
```

is state, and:

```jsx
setCount
```

updates that state.

### Props vs State

| Props                                | State                                                |
| ------------------------------------ | ---------------------------------------------------- |
| Passed from parent to child          | Managed by a component                               |
| Read-only to the receiving component | Can be updated using the appropriate state mechanism |
| Used to configure a component        | Used for data that changes over time                 |
| Changes come from the parent         | Updates trigger a new render                         |
| Helps communicate between components | Helps a component remember changing data             |

### Simple Example

```jsx
function App() {
  return <Counter initialValue={10} />;
}
```

Here:

```text
initialValue → prop
count        → state
```

---

## 10. What is the difference between React's class components and functional components?

React supports two main styles of components: **class components** and **function components**.

### Functional Component

A functional component is a JavaScript function that returns React elements.

Example:

```jsx
function Welcome({ name }) {
  return <h1>Hello, {name}</h1>;
}
```

With Hooks, functional components can manage state and other React features.

```jsx
import { useState } from "react";

function Counter() {
  const [count, setCount] = useState(0);

  return (
    <button onClick={() => setCount(count + 1)}>
      Count: {count}
    </button>
  );
}
```

---

### Class Component

A class component extends `React.Component`.

Example:

```jsx
class Welcome extends React.Component {
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}
```

Class components can use lifecycle methods and class state.

```jsx
class Counter extends React.Component {
  state = {
    count: 0
  };

  render() {
    return (
      <button
        onClick={() =>
          this.setState({ count: this.state.count + 1 })
        }
      >
        {this.state.count}
      </button>
    );
  }
}
```

### Functional vs Class Components

| Functional Components                                  | Class Components                                   |
| ------------------------------------------------------ | -------------------------------------------------- |
| JavaScript functions                                   | JavaScript classes                                 |
| Use Hooks for state and other React features           | Use `this.state` and lifecycle methods             |
| No `this` keyword required                             | Uses `this`                                        |
| Generally simpler and more concise                     | Usually more verbose                               |
| Modern React development generally prefers them        | Mainly found in older codebases                    |
| Hooks such as `useState` and `useEffect` are available | Uses lifecycle methods such as `componentDidMount` |

### Which one should you use?

For **new React applications, functional components are generally preferred**.

Hooks provide a straightforward way to use state, effects, context, refs, and other React features without class components.

Class components are still supported and are important to understand when working with older React applications.

---

# Quick Revision

| Topic                    | Key Point                                                        |
| ------------------------ | ---------------------------------------------------------------- |
| **React**                | JavaScript library for building user interfaces                  |
| **JSX**                  | HTML-like syntax used within JavaScript                          |
| **Virtual DOM**          | In-memory representation used during React's UI reconciliation   |
| **Reconciliation**       | Process React uses to determine required UI updates              |
| **React Node**           | Anything React can render                                        |
| **React Element**        | Description of what React should render                          |
| **React Component**      | Reusable unit that produces UI                                   |
| **Fragment**             | Groups elements without adding a DOM element                     |
| **Key**                  | Helps React identify list items                                  |
| **Index as Key**         | Can cause bugs when dynamic lists change                         |
| **Props**                | Data passed into a component                                     |
| **State**                | Data managed by a component that can change                      |
| **Functional Component** | Function-based component, typically using Hooks                  |
| **Class Component**      | Class-based component using `this`, state, and lifecycle methods |
