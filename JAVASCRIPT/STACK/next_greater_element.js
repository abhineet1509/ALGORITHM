
function nextGreater(nums) {
    let stack = [];
    let res = Array(nums.length).fill(-1);
  
    for (let i = nums.length - 1; i >= 0; i--) {
      while (stack.length && stack[stack.length - 1] <= nums[i])
        stack.pop();
  
      if (stack.length) res[i] = stack[stack.length - 1];
      stack.push(nums[i]);
    }
    return res;
  }
  
  function prevGreater(nums) {
    let stack = [];
    let res = Array(nums.length).fill(-1);
  
    for (let i = 0; i < nums.length; i++) {
      while (stack.length && stack[stack.length - 1] <= nums[i])
        stack.pop();
  
      if (stack.length) res[i] = stack[stack.length - 1];
      stack.push(nums[i]);
    }
    return res;
  }
  
  function nextSmaller(nums) {
    let stack = [];
    let res = Array(nums.length).fill(-1);
  
    for (let i = nums.length - 1; i >= 0; i--) {
      while (stack.length && stack[stack.length - 1] >= nums[i])
        stack.pop();
  
      if (stack.length) res[i] = stack[stack.length - 1];
      stack.push(nums[i]);
    }
    return res;
  }
  