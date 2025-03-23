// 5 minutes, no reference to solution
class Solution {
    public:
        int trap(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int count = 0;
            int low = 0;
            while (left < right)
            {
                low = max(low, min(height[left], height[right]));
                count += low - min(height[left], height[right]);
                if (height[left] > height[right])
                {
                    right--;
                } else 
                {
                    left++;
                }
            }
            return count;
        }
    };