// 210. Course Schedule II 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> graph(numCourses);
      queue<int> visited; 
      vector<int> ans;
      vector<int> indegrees(numCourses, 0);

      for (const vector<int>& p : prerequisites) {
        const int u = p[0];
        const int v = p[1];
        graph[v] = u;
        ++indegrees[u];
      }

      for (const int node : numCourses) {
        if (indegrees[node] == 0) {
          visited.push_back(node);
        }
      }

      while (!visited.empty()) {
        const int u = visited.front();
        visited.pop();
        ans.push_back(u);
        for (const int v : graph[u]) {
          if (--inDegrees[v] == 0)
            q.push(v);
        }
      }
      
      return ans.size() == numCourses ? ans : vector<int>();

    }
};
