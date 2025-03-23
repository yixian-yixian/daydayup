// 20 m, rewrite for O(1) space complexity 
// given the nums1 already have a size of (m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int p1 = m - 1; int p2 = n - 1; // trace from the back 
      for (int p = n + m - 1; p >= 0; p --) {
        if (p2 < 0) break; // reach the end of nums2 
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
          nums1[p] = nums1[p1--];
        } else {
          nums1[p] = nums2[p2--]; 
        }
      }
    }
};
