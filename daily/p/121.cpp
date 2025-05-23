// 5 minutes 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int minprice = INT_MAX;
	int maxprofit = 0;
	for (int i = 0; i < prices.size(); i++) {
		minprice = min(prices[i], minprice);
		maxprofit = max(prices[i] - minprice, maxprofit);
	}     
	return maxprofit;
    }
};
