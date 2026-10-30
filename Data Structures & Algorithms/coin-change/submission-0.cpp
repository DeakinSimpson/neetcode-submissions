class Solution {
    // amount, coins
    std::unordered_map<int, int> cache;
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int res { INT_MAX };

        res = std::min(res, dfs(amount, coins));
        
        if (res == INT_MAX)
        {
            return -1;
        }

        return res;
    }

    int dfs(int a, const std::vector<int>& coins)
    {
        // if amount == 0 return 0
        if (a ==0) { return 0; }

        // if cache.find(amound) return cache[amount]
        if (cache.find(a) != cache.end()) { return cache[a]; }

        // set a min value to max
        int res { INT_MAX };

        // loop over each coin (unlimited)
        for (auto coin : coins)
        {
            // get dfs
            if (a - coin >= 0)
            {
                int dfsRes { dfs(a - coin, coins) };
                // if dfs != max
                if (dfsRes != INT_MAX)
                {
                    res = std::min(res, dfsRes + 1);
                }

                    // min = min (min, dfs + 1 (cur depth))
            }
        }

        cache[a] = res;
        // cache[a] = min val

        // return min
        return res;
    }
};
