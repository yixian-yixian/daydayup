// 10 minutes 
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
      const int n = nums.size();
      vector<int> l(n, 1); vector<int> c(n, 1);
      for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (nums[i] > nums[j]) {
            if (l[i] < l[j] + 1) {
              l[i] = l[j] + 1;
              c[i] = c[j];
            } else if (l[i] == l[j] + 1) {
              c[i] += c[j];
            }
          }
        }
      }
      int max_len = *max_element(l.begin(), l.end());
      int ans = 0;
      for(int i = 0; i < n; ++i){
        if (l[i] == max_len){
          ans += c[i];
        }
      }
      return ans;
    }
};
