// 5 minutes, similar vein as last 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<vector<int>> result; 
      for (auto& p : intervals) {
        if (result.empty() || p[0] > result.back()[1]) {
          result.push_back(p);
        } else {
          result.back()[1] = max(p[1], result.back()[1]);
        }
      }
      return result;
    }
};
