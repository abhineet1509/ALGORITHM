function submatrixSum(matrix, k) {
    let m = matrix.length, n = matrix[0].length;
    let count = 0;
  
    for (let top = 0; top < m; top++) {
      let arr = Array(n).fill(0);
      for (let bottom = top; bottom < m; bottom++) {
        for (let c = 0; c < n; c++)
          arr[c] += matrix[bottom][c];
  
        let map = new Map();
        map.set(0, 1);
        let sum = 0;
  
        for (let val of arr) {
          sum += val;
          if (map.has(sum - k))
            count += map.get(sum - k);
          map.set(sum, (map.get(sum) || 0) + 1);
        }
      }
    }
    return count;
  }
  