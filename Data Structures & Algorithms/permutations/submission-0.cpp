class Solution {
public:
std::vector<std::vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<int> cur;   
        std::vector<bool> curVal(nums.size(), false);
        backtrack(nums, cur, curVal);

        return result; 
    }

    void backtrack(std::vector<int>& nums, std::vector<int>& cur, std::vector<bool>& curVal)
    {
        if (cur.size() == nums.size())
        {
            result.push_back(cur);
            return;
        }

        for (int i {}; i < nums.size(); ++i)
        {
            if (!curVal[i])
            {
                cur.push_back(nums[i]);
                curVal[i] = true;
                backtrack(nums, cur, curVal);

                cur.pop_back();
                curVal[i] = false;
            }
        }
    }
};
