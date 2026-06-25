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
    int answer = 0;

    void dfs(TreeNode*root, int maxSoFar) {
        if(root == nullptr) {
            return;
        }

        if(root->val >= maxSoFar) {
            answer++;
        }

        maxSoFar = max(maxSoFar, root->val);

        dfs(root->left, maxSoFar);
        dfs(root->right, maxSoFar);
    }
    int goodNodes(TreeNode* root) {
        int maxSoFar;

        dfs(root, root->val);

        return answer;
    }
};
