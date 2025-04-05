// 10 minutes
class NumArray {
public:
    NumArray(vector<int>& nums): prefix_sum(nums.size() + 1, 0) {
	for (int i = 0; i < nums.size(); i++ ) {
	  prefix_sum[i+1] = prefix_sum[i] + nums[i];
	}
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right + 1] - prefix_sum[left];
    }

private:
  vector<int> prefix_sum;

};
