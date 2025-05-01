// 7 minutes 
class Solution {
    public:
        bool isBoomerang(vector<vector<int>>& points) {
            int x1, x2, x3;
            int y1, y2, y3;
            vector<int> point1{points.at(0)}, point2{points.at(1)}, point3{points.at(2)};
            x1 = point1.at(0);
            y1 = point1.at(1);
            x2 = point2.at(0);
            y2 = point2.at(1);
            x3 = point3.at(0);
            y3 = point3.at(1);
    
            return !((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1));
        }
    };