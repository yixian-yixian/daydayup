// 10 minutes, based on hint, but this feels like a maths problem
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
      // load all available numbers 
      vector<int> range; 
      for (const vector<int>& row : grid) {
        range.insert(range.end(), row.begin(), row.end());
      }
      // if any of them has a different mod result, cannot happen 
      if (ranges::any_of(range, [&](int a) {return (a - range[0]) % x; }))
        return -1; 

      int ans = 0;
      nth_element(range.begin(), range.begin() + range.size() / 2, range.end());


      for (const int r : range) {
        ans += abs(r - range[range.size() / 2]) / x; 
      }

      return ans;
    }
};
