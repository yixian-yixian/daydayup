// 33 minutes, sorry not sorry stuck on >=3 condition 
class Solution {
public:
    using range = pair<int, int>;
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<range> x_range, y_range; 
        for (auto& pos : rectangles) {
          x_range.emplace_back(pos[0], pos[2]); 
          y_range.emplace_back(pos[1], pos[3]);
        }
        return max(mergeRange(x_range), mergeRange(y_range)) >= 3;

    }
private:
    int mergeRange(vector<range>& one_range) {
      int lastEnd = 0, count = 0;
      ranges::sort(one_range);
      for (auto& [startP, endP] : one_range) {
        if (startP < lastEnd) {
          lastEnd = max(lastEnd, endP);
        } else {
          lastEnd = endP;
          count += 1;
        }
      }
      return count;
    }
};
