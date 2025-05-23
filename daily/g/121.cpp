class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profit = 0;
            int lowest_price = INT_MAX;
            for (int price: prices)
            {
                lowest_price = min(lowest_price, price);
                max_profit = max(max_profit, price - lowest_price);
            }
            return max_profit;
        }
    };