// 733. Flood Fill 

class Solution {

public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    dfs(image, sr, sc,
        vector<vector<bool>>(image.size(), vector<bool>(image[0].size())),
        image[sr][sc], newColor);
    return image;
  }

private: 
  int dfs(vector<vector<int>>& image, int i, int j,
          vector<vector<bool>>&& flooded, int startColor, int endColor) {
    if (i < 0 || i == image.size() || j < 0 || j == image[0].size())
      return;
    if (image[i][j] != startColor || flooded[i][j])
      return;
    
    image[i][j] = newColor;
    flooded[i][j] = true;

    dfs(image, i + 1, j, std::move(flooded), startColor, newColor);
    dfs(image, i - 1, j, std::move(flooded), startColor, newColor);
    dfs(image, i, j + 1, std::move(flooded), startColor, newColor);
    dfs(image, i, j - 1, std::move(flooded), startColor, newColor);
}


}
