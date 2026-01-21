class Stack {
    constructor() {
      this.q = [];
    }
  
    push(x) {
      this.q.push(x);
      for (let i = 0; i < this.q.length - 1; i++) {
        this.q.push(this.q.shift());
      }
    }
  
    pop() {
      return this.q.shift();
    }
  }
  