class Solution {
    public:
        unordered_map<int, long long> cache;
        long long dp(int i, vector<vector<int>> &questions)
        {
            if (i >= questions.size())
            {
                return 0;
            }
            if (cache.find(i) == cache.end())
            {
                int p = questions.at(i).at(0);
                int d = questions.at(i).at(1);
                long long most_point = max(p + dp(i + d + 1, questions), dp(i + 1, questions));
                cache[i] = most_point;
            }
            return cache[i];
        }
        long long mostPoints(vector<vector<int>>& questions) {
            return dp(0, questions);
        }
    };