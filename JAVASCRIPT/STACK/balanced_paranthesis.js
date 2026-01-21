function isBalanced(s) {
    let stack = [];
    let map = { ')': '(', '}': '{', ']': '[' };
  
    for (let ch of s) {
      if (ch === '(' || ch === '{' || ch === '[') {
        stack.push(ch);
      } else {
        if (!stack.length || stack.pop() !== map[ch]) return false;
      }
    }
    return stack.length === 0;
  }
  
