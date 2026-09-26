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
    bool isBalanced(TreeNode* root) {
        // if there is no root node return true
        if (!root) { return true; }

        // get left & right height
        int left { height(root->left) };
        int right { height(root->right) };

        // if abs(left - right) > 1, then unbalanced
        if (abs(left - right) > 1) { return false; }

        // return if left && right is balanced (recurisvely)
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root)
    {
        // if no node return 0
        if (!root) { return 0; }

        // retrun the max of the height-left and height-right
        return 1 + std::max(height(root->left), height(root->right));
    }
};
