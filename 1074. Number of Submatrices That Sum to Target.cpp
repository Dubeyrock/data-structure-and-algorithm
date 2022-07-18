Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

 

Example 1:


Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
Example 3:

Input: matrix = [[904]], target = 0
Output: 0
 

Constraints:

1 <= matrix.length <= 100
1 <= matrix[0].length <= 100
-1000 <= matrix[i] <= 1000
-10^8 <= target <= 10^8



/*approach*/

This problem is essentially a 2-dimensional version of #560. Subarray Sum Equals K (S.S.E.K). By using a prefix sum on each row or each column, we can compress this problem down to either N^2 iterations of the O(M) SSEK, or M^2 iterations of the O(N) SSEK.

In the SSEK solution, we can find the number of subarrays with the target sum by utilizing a result map (res) to store the different values found as we iterate through the array while keeping a running sum (csum). Just as in the case with a prefix sum array, the sum of a subarray between i and j is equal to the sum of the subarray from 0 to j minus the sum of the subarray from 0 to i-1.

Rather than iteratively checking if sum[0,j] - sum[0,i-1] = T for every pair of i, j values, we can flip it around to sum[0,j] - T = sum[0,i-1] and since every earlier sum value has been stored in res, we can simply perform a lookup on sum[0,j] - T to see if there are any matches.

When extrapolating this solution to our 2-dimensional matrix (M), we will need to first prefix sum the rows or columns, (which we can do in-place to avoid extra space, as we will not need the original values again). Then we should iterate through M again in the opposite order of rows/columns where the prefix sums will allow us to treat a group of columns or rows as if it were a 1-dimensional array and apply the SSEK algorithm.

  
  
  /* code*/
  
  
  
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& M, int T) {
        int xlen = M[0].size(), ylen = M.size(), ans = 0;
        unordered_map<int, int> res;
        for (int i = 0; i < ylen; i++)
            for (int j = 1; j < xlen; j++)
                M[i][j] += M[i][j-1];
        for (int j = 0; j < xlen; j++)
            for (int k = j; k < xlen; k++) {
                res.clear();
                res[0] = 1;
                int csum = 0;
                for (int i = 0; i < ylen; i++) {
                    csum += M[i][k] - (j ? M[i][j-1] : 0);
                    ans += res.find(csum - T) != res.end() ? res[csum - T] : 0;
                    res[csum]++;
                }
            }
        return ans;
    }
};



