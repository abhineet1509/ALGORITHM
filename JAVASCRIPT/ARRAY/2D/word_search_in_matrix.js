function exist(board, word) {
    let m = board.length, n = board[0].length;
  
    function dfs(i, j, idx) {
      if (idx === word.length) return true;
      if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] !== word[idx])
        return false;
  
      let temp = board[i][j];
      board[i][j] = '#';
  
      let found =
        dfs(i+1,j,idx+1) || dfs(i-1,j,idx+1) ||
        dfs(i,j+1,idx+1) || dfs(i,j-1,idx+1);
  
      board[i][j] = temp;
      return found;
    }
  
    for (let i = 0; i < m; i++)
      for (let j = 0; j < n; j++)
        if (dfs(i, j, 0)) return true;
  
    return false;
  }
  