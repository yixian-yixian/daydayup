// 10 minutes, reference to cpp syntax on sorting 
class Solution {
  public:
    int countDays(int days, vector<vector<int>>& meetings) {
      // sort meetings by start date 
      sort(meetings.begin(), meetings.end()); // default use first element 
      int lastDay = 0, freeDays = 0;
      for (auto& m : meetings) {
        int s = m[0], e = m[1];
        if (s > lastDay + 1) {
          freeDays += s - lastDay - 1;
        }
        lastDay = max(e, lastDay);
      }
      freeDays += days - lastDay;
      return freeDays;
    }
};
