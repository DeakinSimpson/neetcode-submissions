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
    vector<int> rightSideView(TreeNode* root)
    {
        if (!root) return {};

        using Level = int;
        std::queue<std::pair<TreeNode*, Level>> q;
        std::unordered_set<Level> usedLevels;
        std::vector<int> res;

        q.push(std::make_pair(root, 0));

        while (!q.empty())
        {
            auto [node, level] { q.front() };
            q.pop();

            if (node->right) q.push(std::make_pair(node->right, level + 1));
            if (node->left) q.push(std::make_pair(node->left, level + 1));
            
            if (usedLevels.contains(level)) { continue; }

            usedLevels.insert(level);
            res.push_back(node->val);
        }
         
         return res;
    }
};
