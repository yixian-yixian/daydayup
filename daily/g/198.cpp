class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            nums.push_back(0);
            nums.push_back(0);
            for (int i = n - 1; i >= 0; --i)
            {
                nums.at(i) = max(nums.at(i) + nums.at(i + 2), nums.at(i + 1));
            }
            return nums.at(0);
        }
    };