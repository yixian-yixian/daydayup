// 
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int max1 = rob_range(nums, 0, nums.size() -2);
        int max2 = rob_range(nums, 1, nums.size() - 1);
        return max(max1,max2);
    }

private:
  int rob_range(vector<int>& nums, int start, int end) {
    vector<int> local(end - start + 1, 0);
    if (start == end) return nums[start];
    local[0] = nums[start]; local[1] = max(nums[start], nums[start + 1]);
    for (int i = 2; i < local.size(); i++) {
      local[i] = max(local[i-2] + nums[start + i],local[i-1]);
    }
    return local.back();
  }

};
