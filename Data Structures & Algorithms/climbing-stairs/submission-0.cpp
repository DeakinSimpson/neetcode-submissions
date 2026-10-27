class Solution {
public:
    std::vector<int> cache;

    int climbStairs(int n)
    {
        // set all values of the cache to -1 
        cache.resize(n, -1);

        // start dfs from step 0
        return dfs(n, 0);
    }

    int dfs(const int n, const int i)
    {
        // if index >= size of cache
        if (i >= n)
        {
            // if i == n (top) return 1, the step is the top
            // if i > n (went past top), return 0 as this is not a valid path
            return i == n;
        }
        // check if there is a cached value for the current step
        // (to reduce running dfs on values already had them tun)
        if (cache[i] != -1)
        {
            return cache[i];
        }

        cache[i] = dfs(n, i + 1) + dfs(n, i + 2);

        return cache[i];
    }
};
