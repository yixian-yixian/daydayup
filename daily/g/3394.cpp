// timeout
// need reference solution
class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            sort(rectangles.begin(), rectangles.end(), [](vector<int> &rec1, vector<int> &rec2){ return rec1[0] < rec2[0];});
            int gaps_found = -1;
            int farthest_x = 0;
            for (const vector<int> &rectangle: rectangles)
            {
                int start_x = rectangle[0];
                int end_x = rectangle[2];
                if (start_x >= farthest_x)
                {
                    gaps_found++;
                }
                farthest_x = max(farthest_x, end_x);
            }
    
            if (gaps_found >= 2)
            {
                return true;
            }
    
            gaps_found = -1;
            int farthest_y = 0;
            sort(rectangles.begin(), rectangles.end(), [](vector<int> &rec1, vector<int> &rec2){ return rec1[1] < rec2[1];});
            for (const vector<int> &rectangle: rectangles)
            {
                int start_y = rectangle[1];
                int end_y = rectangle[3];
                if (start_y >= farthest_y)
                {
                    gaps_found++;
                }
                farthest_y = max(farthest_y, end_y);
            }
            return gaps_found >= 2;
        }
    };