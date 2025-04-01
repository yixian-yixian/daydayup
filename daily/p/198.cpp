// 10 minutes 
class Solution {
public:
    int rob(vector<int>& nums) {
      int N = nums.size();
      if (!N) return 0; // empty number of houses 
      vector<int> maxRob(N + 1, -1);
      maxRob[N] = 0; maxRob[N-1] = nums[N - 1]; // base case 
      for (int i = N - 2; i >= 0; --i) {
        maxRob[i] = max(maxRob[i+1], maxRob[i+2] + nums[i]); 
      }
      return maxRob[0];
    }
};
