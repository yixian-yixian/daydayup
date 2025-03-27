// 10 minutes with the hint, but not sure what my take home message is for this problem 
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
      // a number is dominant if more than half the elements of arr have a value of x
      unordered_map<int, int> range1_cnt;
      unordered_map<int, int> range2_cnt; 
      int n = nums.size();
      for (const int n : nums) {
          ++range2_cnt[n]; // increment current number frequency 
      }

      for (int i = 0; i < n; ++i) {
        const int freq1 = ++range1_cnt[nums[i]];
        const int freq2 = --range2_cnt[nums[i]];
        if (freq1 * 2 > i + 1 && freq2 * 2 > n - 1 - i)
          return i;
        }
        return -1;
    }
};
