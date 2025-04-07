// 20 minutes 
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      const int m = dungeon.size();
      const int n = dungeon[0].size();
      // take minimum between down and right
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
      // set up prep steps to go into princess' slot
      dp[m][n - 1] = 1; dp[m - 1][n] = 1;
      for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
          // take minimum between right and down 
          dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
      }

      return dp[0][0];
    }
};
