// 20 minutes 
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
	int ans = 0;
	unordered_map<int, int> location;
	for (const int a : arr) {
	  if (auto it = location.find(a - difference); it != location.end()) {
	    location[a] = location[a - difference] + 1;
	  }
	  else {
	    location[a] = 1;
	  }
	  ans = max(location[a], ans);
	}	 
	return ans;      
    }
};
