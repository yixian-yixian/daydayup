// 10 minutes
class Solution {
    public:
        unordered_map<int, int> ele_to_position;
        unordered_map<int, int> cache;
    
        int dp(int i, int d, vector<int> &arr)
        {
            if (cache.find(i) == cache.end())
            {
                if (ele_to_position.find(arr[i] - d) == ele_to_position.end())
                {
                    cache[i] = 1;
                } else {
                    cache[i] = 1 + dp(ele_to_position[arr[i] - d], d, arr);
                }
            }
            ele_to_position[arr[i]] = i;
            return cache[i];
        }
    
        int longestSubsequence(vector<int>& arr, int difference) {
            int max_length = 0;
            for (int i = 0; i < arr.size(); ++i)
            {
                max_length = max(max_length, dp(i, difference, arr));
            }
            return max_length;
        }
    };