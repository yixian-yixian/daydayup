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
 // Spent more than 30 minutes...
 class Solution {
    public:
        void dfs(TreeNode *node, int &linear, int &overall)
        {
            if (node == nullptr)
            {
                linear = -1;
                overall = -1;
                return;
            }
    
            int left_linear, right_linear, left_overall, right_overall;
            dfs(node->left, left_linear, left_overall);
            dfs(node->right, right_linear, right_overall);
            linear = max(left_linear, right_linear) + 1;
            overall = max(max(left_overall, right_overall), left_linear + right_linear + 2);
        }
    
        int diameterOfBinaryTree(TreeNode* root) {
            int linear, overall;
            dfs(root, linear, overall);
            return overall;
        }
    };