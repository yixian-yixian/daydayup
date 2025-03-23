// 37 minutes - no reference to solution
class Solution {
    public:
        void dfs(int v, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &nodes, int parent)
        {
            if (visited[v])
            {
                return;
            }
            visited[v] = true;
            nodes.push_back(v);
            for (int neighbor: graph[v])
            {
                if (neighbor == parent)
                {
                    continue;
                }
                dfs(neighbor, graph, visited, nodes, v);
            }
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> graph(n, vector<int>());
            vector<vector<bool>> connected(n, vector<bool>(n));
            int count = 0;
            for (auto e: edges)
            {
                int v1 = e[0];
                int v2 = e[1];
                graph[v1].push_back(v2);
                graph[v2].push_back(v1);
                connected[v1][v2] = true;
                connected[v2][v1] = true;
            }
            vector<bool> visited(n, false);
    
            for (int i = 0; i < n; ++i)
            {
                connected[i][i] = true;
                vector<int> nodes;
                if (visited[i])
                {
                    continue;
                }
                dfs(i, graph, visited, nodes, -1);
                bool all_connected = true;
                for (int v1: nodes)
                {
                    for (int v2: nodes)
                    {
    
                        if (v1 == v2)
                        {
                            continue;
                        }
    
                        if (!connected[v1][v2])
                        {
                            all_connected = false;
                            break;
                        }
                    }
                }
                if (all_connected)
                {
                    printf("%d node++\n", i);
                    count++;
                }
            }
            return count;
        }
    };