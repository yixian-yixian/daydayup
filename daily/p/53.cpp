// 5 minutes 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int currSum = nums[0], maxSum = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        currSum = max(currSum, 0) + nums[i];
        maxSum = max(currSum, maxSum);
      }
      return maxSum;
    }
};

