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
    // Function to check if two trees are identical
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;       // both null
        if (!root1 || !root2) return false;      // one null
        if (root1->val != root2->val) return false; // values differ

        // recursively check left and right subtrees
        return isIdentical(root1->left, root2->left) &&
               isIdentical(root1->right, root2->right);
    }

    // Function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;  // reached end of main tree

        // check if trees are identical at this node
        if (isIdentical(root, subRoot)) return true;

        // recursively check left and right subtrees
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
