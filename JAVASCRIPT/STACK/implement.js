// ===============================
// STACK USING ARRAY
// ===============================
class StackArray {
    constructor() {
      this.stack = [];
    }
  
    push(x) {
      this.stack.push(x);
    }
  
    pop() {
      if (this.isEmpty()) return "Underflow";
      return this.stack.pop();
    }
  
    peek() {
      return this.isEmpty() ? "Empty Stack" : this.stack[this.stack.length - 1];
    }
  
    isEmpty() {
      return this.stack.length === 0;
    }
  
    size() {
      return this.stack.length;
    }
  }
  
  // ===============================
  // STACK USING LINKED LIST
  // ===============================
  class Node {
    constructor(val) {
      this.data = val;
      this.next = null;
    }
  }
  
  class StackLinkedList {
    constructor() {
      this.top = null;
      this.length = 0;
    }
  
    push(x) {
      let node = new Node(x);
      node.next = this.top;
      this.top = node;
      this.length++;
    }
  
    pop() {
      if (this.isEmpty()) return "Underflow";
      let val = this.top.data;
      this.top = this.top.next;
      this.length--;
      return val;
    }
  
    peek() {
      return this.isEmpty() ? "Empty Stack" : this.top.data;
    }
  
    isEmpty() {
      return this.top === null;
    }
  
    size() {
      return this.length;
    }
  }
  
  // ===============================
  // DEMO / TEST
  // ===============================
  console.log("=== Stack using Array ===");
  let s1 = new StackArray();
  s1.push(10);
  s1.push(20);
  s1.push(30);
  console.log(s1.pop());   // 30
  console.log(s1.peek()); // 20
  console.log(s1.size()); // 2
  
  console.log("\n=== Stack using Linked List ===");
  let s2 = new StackLinkedList();
  s2.push(5);
  s2.push(15);
  s2.push(25);
  console.log(s2.pop());   // 25
  console.log(s2.peek()); // 15
  console.log(s2.size()); // 2
  