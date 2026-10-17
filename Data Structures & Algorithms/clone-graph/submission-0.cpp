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

        // create a priority hashmap that stores visited nodes by val and std::pair<pointer, std::vector<int> of all the other values
        using NodeVals = std::vector<int>;
        std::unordered_map<int, std::pair<Node*, NodeVals>> q;
    
        // create a queue and push node
        std::queue<Node*> nodeQueue;
        nodeQueue.push(node);

        // while the q is not empty
        while (!nodeQueue.empty())
        {
            // pop the current front
            auto n { nodeQueue.front() };
            nodeQueue.pop();

            // create a new node with val of current node
            auto newNode { new Node(n->val) };

           // create an empty vector of ints
           std::vector<int> nNeighbors;

            // loop through each neighbour
            for (auto neighbor : n->neighbors)
            {
                nNeighbors.push_back(neighbor->val);

                // if neighbour is in the hashmap continue
                if (q.contains(neighbor->val)) { continue; }
                
                // push all neightbours to the q
                nodeQueue.push(neighbor);
                
            }
             // push the val and the pointer vector pair to the current node to the hashmap
            q[n->val] = std::make_pair(newNode, nNeighbors);
        }

        // loop through each value in the hashmap
        for (auto [val, p] : q)
        {
            auto [n, neighbors] { p };
            // for each pointer, get its list of values, and add corresponding pointers to neighbours
            for (auto v : neighbors)
            {
                n->neighbors.push_back(q[v].first);
            }
        }
        // return val of 1 pointer
        return q[1].first;
    }
};
