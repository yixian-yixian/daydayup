class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int m = triangle.size();
            int res = triangle[0][0];
            for (int r = 1; r < m; ++r)
            {
                res = INT_MAX;
                for (int c = 0; c <= r; ++c)
                {
                    if ( c == 0)
                    {
                        triangle[r][c] += triangle[r - 1][c];
                    } 
                    else if (c == r)
                    {
                        triangle[r][c] += triangle[r - 1][c - 1];
                    } else 
                    {
                        triangle[r][c] += min(triangle[r - 1][c - 1], triangle[r - 1][c]);
                    }
                    res = min(res, triangle[r][c]);
                } 
            }
            return res;
        }
    };