class Solution {
    std::unordered_map<int, int> cache;
public:
    int numDecodings(string s)
    {
        cache[s.size()] = 1;
        return dfs(0, s);
    }

    int dfs(const int i, const std::string& s)
    {
        // if at end return 1 as cannot perform double integer dfs
        if (cache.count(i))
        {
            return cache[i];
        }

        // cant perform dfs on 0 out of range
        if (s[i] == '0') 
        {
            return 0;
        }

        // get the dfs of next item
        int res { dfs(i + 1, s) };

        // if next number can be combined into double digit, 
        // dfs from there too (second decision path)
        if ((i < s.size() - 1) && 
            (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7') ))
        {
            res += dfs(i + 2, s); 
        }

        cache[i] = res;
        return res;
    }
};
