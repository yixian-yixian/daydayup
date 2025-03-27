// 5 minutes, recursive  
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> output;
      traverse(root, output);
      return output;
    }

    void traverse(TreeNode* curr,  vector<int>& output) {
      if (curr != nullptr) {
        traverse(curr->left, output);
        output.push_back(curr->val);
        traverse(curr->right, output);
      }
    }
};


class Solution {
  public:
    vector<int> inorderTraversal_iterative(TreeNode* root) {
      vector<int> output; 
      stack<TreeNode *> stk;
      while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
          stk.push(root);
          root = root->left;
        }
        root = stk.top(), stk.pop();
        output.push_back(root);
        root = root->right;
      }
      return output;
    }
}
