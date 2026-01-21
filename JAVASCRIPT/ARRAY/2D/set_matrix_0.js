function setZeroes(matrix) {
    let rows = matrix.length, cols = matrix[0].length;
    let row0 = false, col0 = false;
  
    for (let i = 0; i < rows; i++)
      if (matrix[i][0] === 0) col0 = true;
  
    for (let j = 0; j < cols; j++)
      if (matrix[0][j] === 0) row0 = true;
  
    for (let i = 1; i < rows; i++)
      for (let j = 1; j < cols; j++)
        if (matrix[i][j] === 0)
          matrix[i][0] = matrix[0][j] = 0;
  
    for (let i = 1; i < rows; i++)
      for (let j = 1; j < cols; j++)
        if (matrix[i][0] === 0 || matrix[0][j] === 0)
          matrix[i][j] = 0;
  
    if (row0) matrix[0].fill(0);
    if (col0) for (let i = 0; i < rows; i++) matrix[i][0] = 0;
  
    return matrix;
  }
  