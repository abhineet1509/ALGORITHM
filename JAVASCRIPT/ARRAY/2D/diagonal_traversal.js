function diagonalTraversal(matrix) {
    let res = [];
    let m = matrix.length, n = matrix[0].length;
  
    for (let d = 0; d < m + n - 1; d++) {
      let temp = [];
      let r = d < n ? 0 : d - n + 1;
      let c = d < n ? d : n - 1;
  
      while (r < m && c >= 0) {
        temp.push(matrix[r][c]);
        r++; c--;
      }
      if (d % 2 === 0) temp.reverse();
      res.push(...temp);
    }
    return res;
  }
  