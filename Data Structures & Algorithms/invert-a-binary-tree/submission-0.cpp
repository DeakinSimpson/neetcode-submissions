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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        // create a queue of nodes that we still need to traverse
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* n { q.front() };
            q.pop();
            std::swap(n->left, n->right);

            if (n->left)
            {
                q.push(n->left);
            }

            if (n->right)
            {
                q.push(n->right);
            } 
        } 

        return root;
    }
};
