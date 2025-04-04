class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            std::sort(intervals.begin(), intervals.end(), [](vector<int> &i1, vector<int> &i2){
                return i1.at(0) < i2.at(0);
            });
            vector<vector<int>> result;
            int s, e;
            for (auto &i: intervals)
            {
                if (result.empty() || e < i.at(0))
                {
                    result.push_back(i);
                    s = i.at(0);
                    e = i.at(1);
                } else if (i.at(1) > result.back().at(1)) {
                    result.pop_back();
                    e = i.at(1);
                    result.push_back({s, e});
                }
            }
            return result;
        }
    };