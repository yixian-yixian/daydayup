#define COOLDOWN 0
#define HOLD 1
#define SELL 2

class Solution {
    vector<vector<int>> cache;
public:
    int dp(vector<int> &prices, int i, int state)
    {
        if (i <= 0)
        {
            return state == HOLD ? -prices[i] : 0;
        }

        if (cache[i][state] == -1)
        {
            if (state == COOLDOWN)
            {
                cache[i][state] = max(dp(prices, i - 1, COOLDOWN), dp(prices, i - 1, SELL));
            }
            else if (state == HOLD)
            {
                cache[i][state] = max(-prices[i] + dp(prices, i - 1, COOLDOWN), dp(prices, i - 1, HOLD));
            }
            else if (state == SELL)
            {
                cache[i][state] = prices[i] + dp(prices, i - 1, HOLD);
            }
        }
        return cache[i][state];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        cache = vector<vector<int>>(n, vector<int>(3, -1));
        return max(dp(prices, n - 1, SELL), dp(prices, n - 1, COOLDOWN));
    }
};