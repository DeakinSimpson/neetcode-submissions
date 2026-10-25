class Solution {
    std::unordered_map<int, std::vector<int>> preMap;
    std::unordered_set<int> visited;
    std::unordered_set<int> allVisited;
    std::vector<int> res;

public:
    vector<int> findOrder(
        int numCourses,
        vector<vector<int>>& prerequisites)
    {
        preMap.clear();
        visited.clear();
        allVisited.clear();
        res.clear();

        for (int c = 0; c < numCourses; ++c)
        {
            preMap[c] = {};
        }

        for (const auto& pres : prerequisites)
        {
            preMap[pres[0]].push_back(pres[1]);
        }

        for (int c = 0; c < numCourses; ++c)
        {
            if (!dfs(c))
            {
                return {};
            }
        }

        return res;
    }

    bool dfs(const int c)
    {
        // A course in the current recursion stack means a cycle.
        if (visited.count(c))
        {
            return false;
        }

        // Its prerequisites have already been processed.
        if (allVisited.count(c))
        {
            return true;
        }

        visited.insert(c);

        for (const auto& crs : preMap[c])
        {
            if (!dfs(crs))
            {
                return false;
            }
        }

        // All prerequisites are complete.
        visited.erase(c);
        allVisited.insert(c);
        res.push_back(c);

        return true;
    }
};