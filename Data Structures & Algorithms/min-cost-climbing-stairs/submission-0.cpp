class Solution {
public:
    std::vector<int> cache;
    int minCostClimbingStairs(vector<int>& cost)
    {
        // resize the cache to be the size of cost
        cache.resize(cost.size(), -1);

        // return the smallest cost of 0 or 1
        return std::min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(const std::vector<int>& cost, const int i)
    {
        if (i >= cost.size())
        {
            return 0;
        }
        if (cache[i] != -1)
        {
            return cache[i];
        }
        cache[i] = cost[i] + std::min(dfs(cost, i + 1), dfs(cost, i + 2));

        return cache[i];
    }
};
