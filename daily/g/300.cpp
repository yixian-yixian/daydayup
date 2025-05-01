class Solution {
    vector<int> cache;
public:
    int dp(vector<int> &nums, int i)
    {
        if (i < 0)
        {
            return 0;
        }

        if (cache[i] == -1)
        {
            cache[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    cache[i] = max(cache[i], dp(nums, j) + 1);
                }
            }
        }
        return cache[i];
    }

    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        cache = vector<int>(n, -1);
        for (int i = 0; i < nums.size(); ++i)
        {
            res = max(res, dp(nums, i));
        }
        return res;
    }
};