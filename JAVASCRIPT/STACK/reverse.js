function reverseString(s) {
    let stack = [];
    for (let ch of s) stack.push(ch);
  
    let res = "";
    while (stack.length) res += stack.pop();
    return res;
  }

  
  function insertAtBottom(stack, x) {
    if (stack.length === 0) {
      stack.push(x);
      return;
    }
    let top = stack.pop();
    insertAtBottom(stack, x);
    stack.push(top);
  }
  
  function reverseStack(stack) {
    if (stack.length === 0) return;
    let top = stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, top);
  }
  