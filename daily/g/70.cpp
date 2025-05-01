// 3 minutes
class Solution {
    public:
        unordered_map<int, int> cache;
    
        int climbStairs(int n) {
            if (n < 0)
            {
                return 0;
            }
            if (cache.find(n) == cache.end())
            {
                int result;
                if (n == 1 || n == 0) 
                {
                    result = 1;
                } else {
                    result = climbStairs(n - 2) + climbStairs(n - 1);
                }
                cache[n] = result;
            }
            return cache[n];
        }
    };