// 5 minutes 
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> d(m, vector<int>(n,1));
      for(int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          d[i][j] = d[i-1][j] + d[i][j-1];
        }
      }
      return d[m-1][n-1];
    }
};
