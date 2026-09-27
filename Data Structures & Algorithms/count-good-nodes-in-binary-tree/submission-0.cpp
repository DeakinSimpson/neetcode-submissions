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
    int goodNodes(TreeNode* root)
    {
        if (!root) return 0;
        
        int res {};
        std::stack<std::pair<TreeNode*, int>> s;
        s.push(std::make_pair(root, -INT_MAX));

        while (!s.empty())
        {
            auto [node, max] { s.top() };
            s.pop();

            if (node->val >= max) ++res;

            if (node->left) 
                s.push(std::make_pair(node->left, std::max(max, node->val)));
            if (node->right)
                s.push(std::make_pair(node->right, std::max(max, node->val)));
        }

        return res;
    }
};
