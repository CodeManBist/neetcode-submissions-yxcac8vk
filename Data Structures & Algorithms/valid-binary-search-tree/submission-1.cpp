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
    bool dfs(TreeNode* root, long long minAllowed, long long maxAllowed) {
        if(root == nullptr) return true;

        if(root->val <= minAllowed || root->val >= maxAllowed) return false;

        return (dfs(root->left, minAllowed, root->val)) &&
        (dfs(root->right, root->val, maxAllowed));

    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};
