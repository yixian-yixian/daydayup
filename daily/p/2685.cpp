// 40 minutes, reviewed union find + disjoin set 
// Time Complexity: O(n + m(n))  --> not so sure
// Space Complexity: O(n)
class Solution {
  public:
	int countCompleteComponents(int n, vector<vector<int>>& edges) {
      // disjoint set union 
      UnionFind dsu(n); unordered_map<int, int> edgeCnt;
      // create components 
      for (const auto& edge : edges) {
          // each component starts with size 1 
          // initializing each set first
          dsu.unionSets(edge[0], edge[1]);
      }

      for (const auto& edge : edges) { 
            int root = dsu.find(edge[0]);
            edgeCnt[root] += 1;
        }

        int completeCnt = 0;
        for (int v = 0; v < n; v++) {
            if (dsu.find(v) == v) {
                int nodeCnt = dsu.size[v];
                int expectedEdges = (nodeCnt * (nodeCnt - 1)) / 2;
                if (edgeCnt[v] == expectedEdges) {
                  // complete connected components have edges between every vertice
                    completeCnt++;
                }
            }
        }
        return completeCnt;

	}

  private:
  class UnionFind {
    public:
       // member 
        vector<int> parent; // track parent of each node 
                            // root component has parent of itself
        vector<int> size;   // track size of each component 
        // constructor 
        UnionFind(int n): parent(n, -1), size(n,1){}
        
        // find root of a disjoint set
        int find(int node){
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // union two components 
        void unionSets(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);
            if (root1 == root2) {
                return;
            }

            // merge smaller component into larger one 
            if (size[root1] > size[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
            }
        }

  }
}
