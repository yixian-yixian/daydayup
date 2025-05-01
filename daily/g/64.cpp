class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            for (int r = 0; r < m; ++r)
            {
                for (int c = 0; c < n; ++c)
                {
                    int candidate = r == 0 && c == 0 ? 0 : INT_MAX;
                    if (r > 0)
                    {
                        candidate = grid[r - 1][c];
                    }
    
                    if (c > 0)
                    {
                        candidate = min(candidate, grid[r][c - 1]);
                    }
                    grid[r][c] += candidate;
                }
            }
            return grid.back().back();
        }
    };