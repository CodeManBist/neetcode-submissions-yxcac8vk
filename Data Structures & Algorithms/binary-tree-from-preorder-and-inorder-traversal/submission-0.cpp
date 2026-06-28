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
    int preIndex = 0;
    vector<int> pre;
    vector<int> in;

    TreeNode* build(int left, int right) {
        if(left > right) return nullptr;

        TreeNode* root = new TreeNode(pre[preIndex++]);

        int mid = left;

        while(in[mid] != root->val) {
            mid++;
        }

        root->left = build(left, mid - 1);
        root->right = build(mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        preIndex = 0;
        
        return build(0, inorder.size() - 1);
    }
};
