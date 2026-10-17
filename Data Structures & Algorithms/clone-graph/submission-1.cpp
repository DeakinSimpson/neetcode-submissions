/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        if (!node) { return nullptr; }

        std::unordered_map<Node*, Node*> oldToNewNodes;
        oldToNewNodes[node] = new Node(node->val);

        std::queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            auto n { q.front() };
            q.pop();

            for (auto nei : n->neighbors)
            {
                if (oldToNewNodes.find(nei) == oldToNewNodes.end())
                {
                    oldToNewNodes[nei] = new Node(nei->val);
                    q.push(nei);
                }

                oldToNewNodes[n]->neighbors.push_back(oldToNewNodes[nei]);
            }
        }

        return oldToNewNodes[node];
    }
};
