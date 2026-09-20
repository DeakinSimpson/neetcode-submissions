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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int maxDepth {};
        int curDepth {};
        std::queue<std::pair<TreeNode*, int>> q {};
        q.push(std::make_pair(root, 1));

        while (!q.empty())
        {
            root = q.front().first;
            curDepth = q.front().second;
            q.pop();

            if (root->left) { q.push(std::make_pair(root->left, (curDepth + 1))); }
            if (root->right) { q.push(std::make_pair(root->right, (curDepth + 1))); }
            if (curDepth > maxDepth) { maxDepth = curDepth; }
        }

        return maxDepth;
    }
};
