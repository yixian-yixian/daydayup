
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
  unordered_map<Node*, Node*> seen;
  Node* copyRandomList(Node* head) {
    if (head == nullptr) { return head; }
    if (seen.find(head) != seen.end()) { return seen[head]; }
    Node* dupe = new Node(head->val);
    seen[head] = dupe;
    dupe->next = copyRandomList(head->next);
    dupe->random = copyRandomList(head->random);
    return dupe;
  }
};
