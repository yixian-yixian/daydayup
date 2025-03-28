
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
      stack<int> res;
      int m = INT_MIN;
      for (int i : preorder) {
        if (i < m) return false;
        while (res.size() && res.top() > i) { m = res.top(); res.pop(); }
        res.push(i);
        return true; 
      }
    }
};
