/*
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
*/

class Solution {
    public:
        unordered_map<Node*, Node*> val_to_copy;
        Node* copyRandomList(Node* head) {
            if (head == nullptr) return nullptr;
            if (val_to_copy.find(head) == val_to_copy.end())
            {
                Node *copy = new Node(head->val);
                val_to_copy[head] = copy;
                copy->next = copyRandomList(head->next);
                copy->random = copyRandomList(head->random);
            }
            return val_to_copy[head];
        }
    };