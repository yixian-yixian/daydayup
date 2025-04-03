// need reference solution
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> flatten;
            int remainder = -1;
            for (auto &row: grid)
            {
                for (auto ele: row)
                {
                    if (remainder == -1)
                    {
                        remainder = ele % x;
                    } else if (ele % x != remainder)
                    {
                        return -1;
                    }
                    flatten.push_back(ele);
                }
            }
            nth_element(flatten.begin(), flatten.begin() + flatten.size() / 2, flatten.end());
            int count = 0;
            for (auto ele: flatten)
            {
                count += abs(ele - flatten[flatten.size() / 2]) / x;
            }
            return count;
        }
    };