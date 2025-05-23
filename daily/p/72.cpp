// Time Complexity O(m * n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        d_ = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
        return minDistance(word1, word2, l1, l2);
    }

private:
  vector<vector<int>> d_;
  int minDistance(const string &word1, const string &word2, int l1, int l2) {
    if (l1 == 0) return l2; 
    if (l2 == 0) return l1;
    if (d_[l1][l2] >= 0) return d_[l1][l2];

    int ans; 
    if (word1[l1-1] == word2[l2-1])
      ans = minDistance(word1, word2, l1-1, l2-1); // no-op if last character is the same 
    else  
      ans = min(minDistance(word1, word2, l1-1,l2-1),
            min(minDistance(word1, word2, l1-1, l2),
                minDistance(word1, word2, l1, l2-1))) + 1;
    
    return d_[l1][l2] = ans;
  }
};

