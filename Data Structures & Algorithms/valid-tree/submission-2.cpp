class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (n - 1 < edges.size())
        {
            return false;
        }

        std::vector<std::vector<int>> edgesByNode(n);

        for (const auto& edge : edges)
        {
            edgesByNode[edge[0]].push_back(edge[1]);
            edgesByNode[edge[1]].push_back(edge[0]);
        }

        std::queue<std::pair<int, int>> q;
        std::unordered_set<int> visited;
        q.push(std::make_pair(0, -1));
        visited.insert(0);

        while(!q.empty())
        {
            auto [cur, parent] { q.front() };
            q.pop();

            for (auto n : edgesByNode[cur])
            {
                if (n == parent)
                {
                    continue;
                }

                if (visited.count(n))
                {
                    return false;
                }

                visited.insert(n);
                q.push(std::make_pair(n, cur));
            }
        }

        return visited.size() == n;
    }
};
