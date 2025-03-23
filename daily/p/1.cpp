// 10 minutes, clean up with c++ syntax 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> numberIdx; 
      for (int i = 0; i < nums.size(); i++) {
        if (const auto it = numberIdx.find(target - nums[i]); it != numberIdx.cend()) {
          return {it->second, i};
        }
        numberIdx[nums[i]] = i;
      }
      throw; // problem stated that we guaranteed a solution 
    }
};
