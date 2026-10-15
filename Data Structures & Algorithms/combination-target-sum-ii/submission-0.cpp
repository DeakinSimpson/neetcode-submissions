class Solution {
public:
    std::vector<std::vector<int>> output;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> cur;
        backtrack(candidates, target, 0, cur, 0);
        return output;

    }

    void backtrack(std::vector<int>& candidates,  int target, int i, 
        std::vector<int>& cur, int total)
    {
        if (total == target)
        {
            output.push_back(cur);
            return;
        }

        if (total > target || i == candidates.size())
        {
            return;
        }

        // push back current, add to total and move to next index in this branch
        cur.push_back(candidates[i]);
        backtrack(candidates, target, i + 1, cur, total + candidates[i]);
        cur.pop_back();

        // get next candidate that is not same as current
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
        {
            ++i;
        }
        backtrack(candidates, target, i + 1, cur, total);
    }
};
