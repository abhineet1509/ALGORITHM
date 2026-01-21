class MinStack {
    constructor() {
      this.stack = [];
      this.minStack = [];
    }
  
    push(x) {
      this.stack.push(x);
      if (
        this.minStack.length === 0 ||
        x <= this.minStack[this.minStack.length - 1]
      ) {
        this.minStack.push(x);
      }
    }
  
    pop() {
      if (this.stack.pop() === this.minStack[this.minStack.length - 1]) {
        this.minStack.pop();
      }
    }
  
    getMin() {
      return this.minStack[this.minStack.length - 1];
    }
  }
  