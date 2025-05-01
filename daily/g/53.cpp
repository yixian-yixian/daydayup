// 8 minutes
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int max_sum = INT_MIN;
            int curr_sum = INT_MIN;
            for (int num: nums) {
                if (curr_sum < 0)
                {
                    curr_sum = num;
                } else {
                    curr_sum += num;
                }
                max_sum = max(max_sum, curr_sum);
            }
            return max_sum;
        }
    };