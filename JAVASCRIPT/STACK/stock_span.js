function stockSpan(prices) {
    let stack = [];
    let span = Array(prices.length);
  
    for (let i = 0; i < prices.length; i++) {
      while (stack.length && prices[stack[stack.length - 1]] <= prices[i])
        stack.pop();
  
      span[i] = stack.length === 0 ? i + 1 : i - stack[stack.length - 1];
      stack.push(i);
    }
    return span;
  }
  