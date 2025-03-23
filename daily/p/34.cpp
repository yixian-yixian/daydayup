// 10 minutes, reviewed lower_bound binary search 
// O(log n) runtime complexity 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      // find first appearance 
      int low = lower_bound(target, nums, 0, nums.size());
      if (low == nums.size() || nums[low] != target) {
        return {-1, -1};
      }
      // find first non-target
      int high = lower_bound(target + 1, nums, low + 1, nums.size());
      return {low, high - 1};
    }
private: 
    int lower_bound(int target, vector<int>& nums, int low, int high) {
      if (low == high){
        return low;
      } else if (low > high) { 
        return -1;
      }
      int mid = low + (high - low)/2;
      if (nums[mid] >= target) {
        return lower_bound(target, nums, low, mid);
      } else {
        return lower_bound(target, nums, mid + 1, high);
      }
    }
};

