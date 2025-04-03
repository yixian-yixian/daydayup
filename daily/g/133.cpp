/*
// Definition for a Node.
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
*/

class Solution {
    unordered_map<int, Node*> val_to_copy;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        {
            return node;
        }
        
        if (val_to_copy.find(node->val) == val_to_copy.end())
        {
            Node *copy = new Node(node->val);
            val_to_copy[node->val] = copy;
            for (Node *neighbor: node->neighbors)
            {
                Node *neighbor_copy = cloneGraph(neighbor);
                copy->neighbors.push_back(neighbor_copy);
            }
        }
        return val_to_copy[node->val];
    }
};