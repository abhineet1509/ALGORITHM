class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        r = len(grid)
        c = len(grid[0])
        # Create DP matrix
        dp = [[0]*c for _ in range(r)]
        
        for i in range(r):
            for j in range(c):
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]  # starting cell
                elif i == 0:
                    dp[i][j] = dp[i][j-1] + grid[i][j]  # first row
                elif j == 0:
                    dp[i][j] = dp[i-1][j] + grid[i][j]  # first column
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        
        return dp[r-1][c-1]  # minimum path sum
grid = [
    [1,3,1],
    [1,5,1],
    [4,2,1]
]

sol = Solution()
print(sol.minPathSum(grid))  # Output: 7
