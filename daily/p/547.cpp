// 547. Number of Provinces 
// Union Find to consolidate all 
// adjacent nodes 
class UnionFind {
  public:
    UnionFind(int n) : count(n), id(n), rank(n) {
      // assign parent node to self
      iota(id.begin(), id.end(), 0);
    }


    // union operation 
    // merge a smaller set to a larger set
    // if two elements are in disjoint set 
    void unionByRank(int i, int j) {
      const int k = find(i);
      const int v = find(j);
      
      if (k == v) {
        return;
      }
      if (rank(k) < rank(v)) {
        id[k] = v;
      } else if (rank(k) > rank(v)) {
        id[v] = k;
      } else {
        id[k] = v;
        ++rank[v];
      }
      --count;
    }


    int getCount() const {
      return count;
    }

  private:
    int count = 0;
    // id[i] = parent of (i)
    vector<int> id;
    vector<int> rank;
    
    int find(int u) {
      // find root parent and decide if two elements 
      // are in the same set 
      return id[u] == u ? u : id[u] = find(id[u]);
    }
    
}


class Solution {
  public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      const int n = isConnected.size();
      UnionFind uf(n);
      
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          // if connected then consolidate
          if (isConnected[i][j] == 1) {
            uf.unionByRank(i, j);
          }
        }
      }
    return uf.getCount();
  }
};
