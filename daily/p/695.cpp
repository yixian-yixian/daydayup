// 695. Max Area of Islands 

class Solution {
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        ans = max(ans, dfs(grid, i, j));
    return ans;
  }


  private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
      if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
        // check for out of bounds 
        return 0; 
      // skip anything that is not an island piece
      if (grid[i][j] != 1)
        return 0;
      
      grid[i][j] = 2; // set as visited 
      
      // dfs all surrounding island 
      return 1 +                                         
           dfs(grid, i + 1, j) + dfs(grid, i - 1, j) +  
           dfs(grid, i, j + 1) + dfs(grid, i, j - 1);

    }

}
