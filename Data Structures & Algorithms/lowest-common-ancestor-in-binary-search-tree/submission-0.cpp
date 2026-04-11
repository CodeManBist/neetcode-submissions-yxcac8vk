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
    bool rootToNodePath(TreeNode* root, TreeNode* n, vector<TreeNode*> &path) {
        if(root == NULL) return false;

        path.push_back(root);

        if(root == n) return true;

        int isLeft = rootToNodePath(root->left, n, path);
        int isRight = rootToNodePath(root->right, n, path);

        if(isLeft || isRight) return true;

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        rootToNodePath(root, p, path1);
        rootToNodePath(root, q, path2);
        
        TreeNode* lca = NULL;
        for(int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
            if(path1[i] != path2[i]) {
                return lca;
            }
            lca = path1[i];
        }
        return lca;
    }
};
