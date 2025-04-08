// 10 minutes 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int hold = INT_MIN, rest = 0, sell = 0; 
      for (const int price : prices) {
        int prev_sell = sell; 
        sell = hold + price;
        hold = max(hold, rest - hold);
        rest = max(rest, prev_sell);
      }
      return max(rest,hold);
    }
};
