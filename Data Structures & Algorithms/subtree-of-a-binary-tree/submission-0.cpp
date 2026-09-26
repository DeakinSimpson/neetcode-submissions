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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (isSameTree(root, subRoot)) { return true; }
        if (root->left && isSubtree(root->left, subRoot)) { return true; }
        if (root->right && isSubtree(root->right, subRoot)) { return true; }

        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        std::stack<TreeNode*> pStack;
        std::stack<TreeNode*> qStack;

        pStack.push(p);
        qStack.push(q);

        while (!pStack.empty() && !qStack.empty())
        {
            // get top nodes
            TreeNode* pCurr { pStack.top() };
            TreeNode* qCurr { qStack.top() };

            // remove top nodes
            pStack.pop();
            qStack.pop();

            if (!pCurr && !qCurr) { continue; }
            if (!pCurr || !qCurr) { return false; }
            
            // check that the nodes are the same
            if (pCurr->val != qCurr->val)
            {
                return false;
            }
        
            pStack.push(pCurr->left);
            pStack.push(pCurr->right);

            qStack.push(qCurr->left);
            qStack.push(qCurr->right);
        }

        return true;
    }
};
