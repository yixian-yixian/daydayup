// 8 minutes
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int write_index = m + n - 1;
            int nums1_index = m - 1;
            int nums2_index = n - 1;
            while (nums1_index >= 0 && nums2_index >= 0)
            {
                if (nums1[nums1_index] > nums2[nums2_index])
                {
                    nums1[write_index--] = nums1[nums1_index--];
                } else {
                    nums1[write_index--] = nums2[nums2_index--];
                }
            }
    
            while (nums1_index >= 0)
            {
                nums1[write_index--] = nums1[nums1_index--];
            }
    
            while (nums2_index >= 0)
            {
                nums1[write_index--] = nums2[nums2_index--];
            }
        }
    };