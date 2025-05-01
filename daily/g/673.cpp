class Solution {
    vector<pair<int, int>> cache;
public:
    pair<int, int> dp(vector<int> &nums, int i)
    {
        if (cache[i].first == 0)
        {
            cache[i] = {1, 1};

            for (int j = 0; j < i; ++j)
            {
                pair<int, int> LIS_curr = cache[i];
                if (nums[j] < nums[i])
                {
                    pair<int, int> LIS_prev = dp(nums, j);
                    if (LIS_prev.first + 1 == LIS_curr.first)
                    {
                        cache[i] = {LIS_curr.first, LIS_curr.second + LIS_prev.second};
                    } 
                    else if (LIS_prev.first + 1 > LIS_curr.first)
                    {
                        cache[i] = {LIS_prev.first + 1, LIS_prev.second};
                    }
                }
            }
        }
        return cache[i];
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        cache = vector<pair<int, int>>(n, {0, 0});
        int LIS = 1;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            pair<int, int> candidate = dp(nums, i);
            if (candidate.first == LIS)
            {
                res += candidate.second;
            }
            else if (candidate.first > LIS)
            {
                LIS = candidate.first;
                res = candidate.second;
            }
        }
        return res;
    }
};