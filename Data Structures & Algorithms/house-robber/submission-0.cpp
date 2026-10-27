class Solution {
public:
    std::vector<int> maxCost;
    int rob(vector<int>& nums)
    {
        maxCost.resize(nums.size(), -1);
        // can make 2 jump or 3 jump, cant start at 0 or 1
        


        return std::max(dfs(nums, 0), dfs(nums, 1));
    }

    int dfs(const std::vector<int>& nums, const int i)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        if (maxCost[i] != -1)
        {
            return maxCost[i];
        }

        maxCost[i] = nums[i] + std::max(dfs(nums, i + 2), dfs(nums, i + 3));

        return maxCost[i];
    }
};
