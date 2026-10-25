class Solution {
    std::unordered_map<int, std::vector<int>> prereqMap;
    std::unordered_set<int> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        // build map to be full of empty vectors
        for (int i {}; i < numCourses; ++i)
        {
            prereqMap[i] = {};
        }

        // loop over each prereq and add to the map
        for (const auto& prereq : prerequisites)
        {
            prereqMap[prereq[0]].push_back(prereq[1]);
        }

        // run a dfs on each course and see if it can be completed
        // if any of them cant, then fail
        for (int i {}; i < numCourses; ++i)
        {
            if (!dfs(i))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(const int crs)
    {
        // check if in visited, if so false because there is a cycle
        if (visited.count(crs))
        {
            return false;
        }

        // if there are no prereqs for course return true
        if (prereqMap[crs].empty())
        {
            return true;
        }

        // add crs into visited
        visited.insert(crs);
        
        // for each prereq of the course, perform a dfs
        for (int prereq : prereqMap[crs])
        {
            // if dfs fails, fail
            if (!dfs(prereq))
            {
                return false;
            }
        }
        // remove crs from visited
        visited.erase(crs);

        // clear course from prereqMap (already completed)
        prereqMap[crs].clear();

        // return true
        return true;
    }
};
