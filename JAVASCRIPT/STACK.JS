class Stack {
    constructor() {
        this.items = [];
    }

    // Push element onto stack
    push(element) {
        this.items.push(element);
        console.log(`${element} pushed into stack`);
    }

    // Pop element from stack
    pop() {
        if (this.isEmpty()) {
            console.log("Stack Underflow");
            return null;
        }
        return this.items.pop();
    }

    // Peek at top element
    peek() {
        if (this.isEmpty()) {
            console.log("Stack is empty");
            return null;
        }
        return this.items[this.items.length - 1];
    }

    // Check if stack is empty
    isEmpty() {
        return this.items.length === 0;
    }

    // Display stack elements
    display() {
        if (this.isEmpty()) {
            console.log("Stack is empty");
            return;
        }
        console.log("Stack elements:", this.items);
    }
}

// Example Usage
const stack = new Stack();
stack.push(10);
stack.push(20);
stack.push(30);
stack.display();
console.log("Top element:", stack.peek());
console.log("Popped element:", stack.pop());
stack.display();
