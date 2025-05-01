// 3 minutes
class NumArray {
    vector<int> accum;
public:
    NumArray(vector<int>& nums) {
        accum = {0};
        for (int num: nums) {
            accum.push_back(accum.back() + num);
        }
    }
    
    int sumRange(int left, int right) {
        return accum[right + 1] - accum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */