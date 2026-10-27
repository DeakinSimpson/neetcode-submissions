class Solution {
    std::vector<std::vector<int>> cache;
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        cache.resize(nums.size(), std::vector<int>(2, -1));

        return std::max(dfs(nums, 0, 1), dfs(nums, 1, 0));
    }

    int dfs(const std::vector<int>& nums, const int i, const int isZeroHouse)
    {
        if (i >= nums.size() || (i >= nums.size() - 1 && isZeroHouse == 1))
        {
            return 0;
        }

        if (cache[i][isZeroHouse] != -1)
        {
            return cache[i][isZeroHouse];
        }

        int newFlag { isZeroHouse };
        if (i == 0)
        {
            newFlag = 1;
        }

        cache[i][isZeroHouse] = std::max(dfs(nums, i + 1, isZeroHouse), 
            nums[i] + dfs(nums, i + 2, newFlag));

        return cache[i][isZeroHouse];
    }
};
