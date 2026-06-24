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
    bool getPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if(root == nullptr) return false;

        path.push_back(root);

        if(root == node) return true;


        bool isLeft = getPath(root->left, node, path);
        bool isRight = getPath(root->right, node, path);

        if(isLeft || isRight) return true;

        path.pop_back();

        return false;   
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        getPath(root, p, path1);
        getPath(root, q, path2);

        int i = 0;

        for(; i < path1.size() && i < path2.size(); i++) {
            if(path1[i] != path2[i]) {
                break;
            }
        }

        return path1[i-1];
    }
};
