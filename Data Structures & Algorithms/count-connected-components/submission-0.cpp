class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        std::unordered_set<int> visited;
        std::vector<std::vector<int>> adj(n);
        int connectedComponents {};

        for (const auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i {}; i < n; ++i)
        {
            if (!visited.count(i))
            {
                ++connectedComponents;
                bfs(i, visited, adj);
            }
        }

        return connectedComponents;
    }

    void bfs(const int startNode, 
        std::unordered_set<int>& visited, 
        std::vector<std::vector<int>>& adj)
    {
        std::queue<int> q;

        q.push(startNode);
        visited.insert(startNode);

        while (!q.empty())
        {
            const int cur { q.front() };
            q.pop();

            for (const auto a : adj[cur])
            {
                if (visited.count(a))
                {
                    continue;
                }

                visited.insert(a);
                q.push(a);
            }
        }
    }
};
