class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            std::sort(meetings.begin(), meetings.end(), [](vector<int> &interval_one, vector<int> &interval_two){
                return interval_one.at(0) < interval_two.at(0);
            });
            int count = 0;
            int current_end = 0;
            for (const auto meeting: meetings)
            {
                int start = meeting.at(0);
                int end = meeting.at(1);
    
                count += max(0, start - current_end - 1);
                current_end = max(end, current_end);
            }
            return count + days - current_end;
        }
    };