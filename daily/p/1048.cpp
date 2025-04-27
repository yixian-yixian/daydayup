
class Solution {
  int longestStrChain(vector<string>& words) {
    int ans = 0;
    unordered_map<string, int> dp; //longest string chain with s as the last word 
    ranges::sort(words, ranges::less{}, [](const string& word) { return word.length(); });
    
    for (const string& word : words) {
      for (int i = 0; i < word.length(); ++i) {
        // iterate through each letter and find its possible predecessor in map
        const string pred = word.substr(0, i) + word.substr(i + 1);
        dp[word] = max(dp[word], (dp.contains(pred) ? dp[pred] : 0) + 1); 
      }
      ans = max(ans, dp[word]);
    }
    return ans;
  }
};
