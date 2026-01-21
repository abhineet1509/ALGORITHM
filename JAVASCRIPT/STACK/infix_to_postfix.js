function evalPostfix(exp) {
    let stack = [];
    for (let ch of exp) {
      if (!isNaN(ch)) stack.push(Number(ch));
      else {
        let b = stack.pop();
        let a = stack.pop();
        if (ch === '+') stack.push(a + b);
        if (ch === '-') stack.push(a - b);
        if (ch === '*') stack.push(a * b);
        if (ch === '/') stack.push(Math.trunc(a / b));
      }
    }
    return stack.pop();
  }
  