// review 
// O(n^2) solution 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      // base case 
      if (nums.size() == 0) {
        return 0;
      }
      vector<int> dp(nums.size(), 1);
      for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
          if (nums[i] > nums[j]) {
            dp[i] = max(dp[i], dp[j] + 1);
          }
        }
      }
      return ranges::max(dp);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> tails;
      for (const int n : nums) {
        if (tails.empty() || n > tails.back()) {
          tails.push_back(n);
        } else {
          int idx = ranges::lower_bound(tails, n) - tails.begin();
          // find position in tails vector to substitute number
          tails[idx] = n;
        }
      }
      return tails.size();
    }
};
