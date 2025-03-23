// 13 minutes, no reference to solution
class Solution {
    public:
        int binary_search(int target, const vector<int> &nums, int low, int high)
        {
            if (low == high)
            {
                return low;
            } else if (low > high)
            {
                return -1;
            }
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
            {
                return binary_search(target, nums, mid + 1, high);
            } 
            else
            {
                return binary_search(target, nums, low, mid);
            }
        }
    
        vector<int> searchRange(vector<int>& nums, int target) {
            int low = binary_search(target, nums, 0, nums.size());
            if (low == nums.size() || nums[low] != target)
            {
                return {-1, -1};
            }
            int high = binary_search(target + 1, nums, 0, nums.size());
            return {low, high - 1};
        }
    };