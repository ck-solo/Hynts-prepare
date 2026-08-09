Q1. What is event bubbling in JavaScript?
Ans. Event bubbling is the process where an event triggers on the target element and then propagates upwards through its parent elements in the DOM tree. When you click a child element, the event first fires on the child, then bubbles up to its parent, grandparent, and so on until it reaches the document root. You can stop this propagation using event.stopPropagation() method.


Q2.Explain bind, call and apply methods in JavaScript?
Ans. These methods control the 'this' context in functions. call() invokes a function with a specified 'this' value and arguments passed individually. apply() is identical but accepts arguments as an array. bind() creates a new function with a permanently bound 'this' value and optional preset arguments, but doesn't immediately invoke it. They're essential for borrowing methods and maintaining proper context.

Q3.What is the difference between map and forEach?
Ans. map() creates and returns a new array with transformed elements based on the callback function, leaving the original array unchanged. forEach() simply iterates through each element executing a callback but returns undefined and doesn't create a new array. Use map() when you need a transformed array, use forEach() for side effects like logging or updating external variables without returning values.

Q4. What is hoisting in JavaScript?
Ans. Hoisting is JavaScript's behavior of moving variable and function declarations to the top of their scope during compilation before code execution. Function declarations are fully hoisted with their definitions. Variables declared with var are hoisted but initialized as undefined. let and const are hoisted but remain in a temporal dead zone until their declaration is reached, causing ReferenceError if accessed early.

Q5. What is the difference between bind and call?
Ans. call() immediately invokes the function with the specified 'this' context and comma-separated arguments. bind() doesn't invoke the function immediately; instead, it returns a new function with the 'this' context permanently bound and optionally preset arguments. Use call() for immediate execution, bind() when you need to pass the function around or use it as an event handler while maintaining context.

Q6.What is the 'this' keyword in JavaScript?
Ans. The 'this' keyword refers to the context object in which a function is executed, changing based on how the function is called. In methods, 'this' refers to the object owning the method. In regular functions, it's the global object (or undefined in strict mode). Arrow functions inherit 'this' from their enclosing scope. Constructor functions and explicit binding (call/apply/bind) can control 'this' value.

Q7. What is a callback function?
Ans. A callback function is a function passed as an argument to another function and executed after the parent function completes its operation. Callbacks enable asynchronous programming, allowing code to run after tasks like API calls, file reads, or timers finish. They're essential for event handling and non-blocking operations, though excessive nesting can lead to callback hell, which Promises and async/await help resolve.


Q8.What is callback hell?    
Ans. Callback hell, also called pyramid of doom, occurs when multiple nested callbacks create deeply indented, hard-to-read code. It happens when handling multiple sequential asynchronous operations, making code difficult to maintain, debug, and reason about. Modern JavaScript addresses this using Promises with .then() chaining or async/await syntax, which flatten the structure and improve readability while maintaining asynchronous behavior.

Q9.What is the difference between callback, promise, and async-await?
Ans. Callbacks are functions passed to handle asynchronous results but can lead to nested code. Promises represent future values with .then() for success and .catch() for errors, enabling cleaner chaining. Async/await is syntactic sugar over Promises, making asynchronous code look synchronous with try/catch for errors. Async/await is most readable, Promises improve upon callbacks, and callbacks are the foundational pattern.

Q10.Explain async-await and its advantages?
Ans. Async/await is modern syntax for handling asynchronous operations built on Promises. The 'async' keyword makes a function return a Promise. The 'await' keyword pauses execution until the Promise resolves. Advantages include synchronous-looking code that's easier to read, simplified error handling with try/catch, better debugging with clear stack traces, and elimination of .then() chaining complexity while maintaining non-blocking behavior.

