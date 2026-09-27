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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        // queue<TreeNode*, int (level)>

        // create a vector<vector<int>> where vector(level) is each level
        
        // push root as root and 0 to the vector and the queue

        // loop through each child, adding to queue and vector
        using Level = int;
        std::queue<std::pair<TreeNode*, Level>> q;
        std::vector<std::vector<int>> res;

        q.push(std::make_pair(root, 0));

        while (!q.empty())
        {
            // get from q
            auto [node, level] { q.front() };
            q.pop();

            // push children to q
            if (node->left) q.push(std::make_pair(node->left, level + 1));
            if (node->right) q.push(std::make_pair(node->right, level + 1));

            // push to vector
            if (res.size() < level + 1) res.push_back({ node->val });
            else res[level].push_back(node->val);
        }


        return res;
    }
};
