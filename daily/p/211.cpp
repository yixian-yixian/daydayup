// 211 
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> ans;
        queue<int> to_visit;
        vector<int> indegrees(numCourses);

        for (const vector<int> p : prerequisites) {
            const int u = p[1];
            const int v = p[0];
            graph[u].push_back(v);
            ++indegrees[v];
        }

        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) {
                to_visit.push(i);
            }
        }

        while(!to_visit.empty()) {
            const int n = to_visit.front(); to_visit.pop();
            for (const int v : graph[n]) {
                if (--indegrees[v] == 0) {
                    to_visit.push(v);
                }
            }
            ans.push_back(n);
        }

        return ans.size() == numCourses ? ans : vector<int>();
        
    }
};
