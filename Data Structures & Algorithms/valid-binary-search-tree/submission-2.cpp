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
    bool isValidBST(TreeNode* root) {
        if (!root) { return true; }

        std::queue<std::tuple<TreeNode*, int, int>> q;
        q.push(std::make_tuple(root, INT_MIN, INT_MAX));

        while (!q.empty())
        {
            auto [node, leftBound, rightBound] { q.front() };
            q.pop();

            if (!(leftBound < node->val && node->val < rightBound))
            {
                return false;
            }

            if (node->left)
            {
                q.push(std::make_tuple(node->left, leftBound, node->val));
            }

            if (node->right)
            {
                q.push(std::make_tuple(node->right, node->val, rightBound));
            }
        }

        return true;
    }
};
