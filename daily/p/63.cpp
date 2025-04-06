// 5 minutes 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      if (obstacleGrid[0][0] == 1) return 0; // no need for traversal 
      const int m = obstacleGrid.size(), n = obstacleGrid[0].size();
      vector<vector<int>> d(m, vector<int>(n, 0)); 
      d[0][1] = 1; d[1][0] = 1;
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          d[i][j] = (!obstacleGrid[i][j]) ? d[i-1][j] + d[i][j-1] : 0;
        }
      }
      return d[m-1][n-1];
    }
};
