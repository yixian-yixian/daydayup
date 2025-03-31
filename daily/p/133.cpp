// 10 minutes, DFS solution O(V+E) traverse through existing vertex and edges
// Space Complexity O(V) for visited dictionary
using namespace::std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

#include <unordered_map>
class Solution {
public:
  std::unordered_map<Node*,  Node*> seen;
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return node;
    }
    if (seen.find(node) != seen.end()) {
      return seen[node];
    }
    Node* new_c = new Node(node->val); 
    seen[node] = new_c;
    for (auto& nei : node->neighbors) { 
      new_c->neighbors.push_back(cloneGraph(nei));
    }
    
    return new_c;
  }
};
