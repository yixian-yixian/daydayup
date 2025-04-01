// 10 minutes 

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
      // iterative recursion 
      int n = questions.size();
      vector<long> maxi_scores(n + 1, 0);
      for (int i = n - 1; i >= 0; --i) {
        const int p = questions[i][0]; const int nextIdx = questions[i][1];
        const int nextP = i + nextIdx + 1;
        const long maxScore_curr = (nextP < n) ? questions[nextP][0] : 0;
        maxi_scores[i] = max(p + maxScore_curr, maxi_scores[i + 1]);
      }

      return maxi_scores[0]; 
    }
};
