576. Out of Boundary Paths
Medium

2155

205

Add to List

Share
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:


Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 

Constraints:

1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
/* code*/

class Solution {
 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    this->m = m;
    this->n = n;
    // dp[k][i][j] := # of paths to move the ball (i, j) out of bound w/ k moves
    dp.resize(maxMove + 1, vector<vector<int>>(m, vector<int>(n, -1)));
    return findPaths(maxMove, startRow, startColumn);
  }

 private:
  constexpr static int kMod = 1e9 + 7;
  int m;
  int n;
  vector<vector<vector<int>>> dp;

  int findPaths(int k, int i, int j) {
    if (i < 0 || i == m || j < 0 || j == n)
      return 1;
    if (k == 0)
      return 0;
    if (dp[k][i][j] != -1)
      return dp[k][i][j];
    return dp[k][i][j] =
      ((findPaths(k - 1, i + 1, j) + findPaths(k - 1, i - 1, j)) % kMod +
       (findPaths(k - 1, i, j + 1) + findPaths(k - 1, i, j - 1)) % kMod) %
        kMod;
  }
};





