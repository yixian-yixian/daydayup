// 10 minutes, reviewed DFS search 
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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }

private: 
    int dfs(TreeNode* node) {
      // base case 
        if (node == nullptr) {
            return 0;
        }
        int left_depth = dfs(node->left);
        int right_depth = dfs(node->right);
        // update current depth 
        res = max(res, left_depth + right_depth);
        return max(left_depth, right_depth) + 1; 
    }
};
