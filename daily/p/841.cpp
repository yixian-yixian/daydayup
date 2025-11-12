// 841. Keys and Rooms 

class Solution {
  public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      vector<bool> seen (rooms.size(), false);
      dfs(rooms, 0, seen);
      return ranges::all_of(seen, [](int s) { return s == true; });
}

  private:
    bool dfs(vector<vector<int>>& rooms, int node, vector<bool>& seen) {
      seen[node] = true;
      for (const int child : rooms[node]) {
        if (!seen[child])
          dfs(rooms, child, seen);
      }
    }

}


