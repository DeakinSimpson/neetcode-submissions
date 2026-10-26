class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        const auto n { edges.size() };

        // create a vector, where parent[i] contains the parent of node[i]
        std::vector<int> parent(n + 1);

        // create an array that contains the size of each set (the root node is what keeps this value)
        std::vector<int> size(n + 1, 1);

        // inialise each node[i] to be its own parent, thus "i"
        for (auto i {0uz}; i < n; ++i)
        {
            parent[i] = i;
        }

        // for each set add the edge perform Union(n1, n2) of the edge
        for (const auto& edge : edges)
        {
            // for the first edge where both nodes are already in the same set
            // thus already connected in some part of the tree, meaning adding this
            // edge will cause a cycle, return the edge
            if (!Union(parent, size, edge[0], edge[1]))
            {
                return { edge[0], edge[1] };
            }
        }
    }

    // finds the set that p is in (if not in any set return self)
    int Find(std::vector<int>& parent, const int n)
    {
        // the default is set to the parent
        int p { parent[n] };

        // while the current node is not the parent of itself (otherwise it is the root node)
        while (p != parent[p])
        {
            // this is called path compression, nodes closer to the root become closer
            // each pass, creating faster traversal for later Find()
            parent[p] = parent[parent[p]];

            // p becomes the parent of its current node (moving up the tree)
            p = parent[p];
        }

        return p;
    }

    // merge the 2 sets containing n1 and n2
    bool Union(std::vector<int>& parent, std::vector<int>& size, const int n1, const int n2)
    {   
        // find the sets that n1 and n2 are apart of
        const int parent1 { Find(parent, n1) };
        const int parent2 { Find(parent, n2) };

        // if they both have the same parents then they are already in the same set
        if (parent1 == parent2)
        {
            return false;
        }

        // merge the smaller set into the larger set
        if (size[parent1] > size[parent2])
        {
            parent[parent2] = parent1;
            size[parent1] += size[parent2];
        }
        else
        {
            parent[parent1] = parent2;
            size[parent2] += size[parent1];
        }

        return true;
    }
};
