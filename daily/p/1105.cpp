class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
      int n = books.size();
      vector<int> dp(n, INT_MAX / 2);
      for (int i = 0; i < n; ++i) {
        int w = 0, h = 0; 
        for (int j = i; j < n; ++j) {
          if ((w += books[j][0]) > shelfWidth) { break;}
          h = max(h, books[j][1]);
          dp[j] = min(dp[j], (i == 0 ? 0 : dp[i-1] + h);
        }
      }
      return dp.back();
    }
};
