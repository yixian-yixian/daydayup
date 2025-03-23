// 55 minutes, reviewed Bellman-Ford and dijkstra
// looked at clean implementation for C++20
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
      vector<vector<pair<int, int>>> graph(n); 
      for (auto &r : roads) {
        int src = r[0], dst = r[1], time = r[2];
        graph[src].emplace_back(dst, time);
        graph[dst].emplace_back(src, time);
      }
      return dijkstra(graph, 0, n - 1);
    }
private: 
    int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dst) {
      constexpr int kMod = 1'000'000'007;
      vector<long> ways(graph.size());
      vector<long> dist(graph.size(), LONG_MAX);
      ways[src] = 1; // one way to self 
      dist[src] = 0; // 0 distance to self 
      
      using P = pair<long, int>;  // (d, u)
      priority_queue<P, vector<P>, greater<>> minHeap; 
      minHeap.emplace(dist[src], src); // sort by distance to src

      while(!minHeap.empty()) {
        const auto [d, u] = minHeap.top();
        minHeap.pop();
        if (d > dist[u]) continue; // greedy 
        for (const auto& [v, w] : graph[u])
          if (d + w < dist[v]) {
            dist[v] = d + w;
            ways[v] = ways[u];
            minHeap.emplace(dist[v], v);
          } else if (d + w == dist[v]) {
            ways[v] += ways[u];
            ways[v] %= kMod;
          }
      }
      return ways[dst];
    }
};

