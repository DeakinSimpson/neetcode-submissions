class Solution {
public:
    void backtrack(std::vector<int>& nums, int target, vector<int>& cur, int i)
    {
        // each loop we reduce target, if target == 0, then we have hit a combination
        if (target == 0)
        {
            res.push_back(cur);
            return;
        }

        // if the combination is larger then the targer or out of bounds, return
        if (target < 0 || i >= nums.size())
        {
            return;
        }
        
        // add the current value to cur
        cur.push_back(nums[i]);

        // backtrack with the nums[i] at current index
        backtrack(nums, target - nums[i], cur, i);

        // remove nums[i]
        cur.pop_back();

        // backtrack down path that does not include nums[i], increase i to push next number instead
        backtrack(nums, target, cur, i + 1);
    }

    std::vector<std::vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        std::vector<int> cur;
        backtrack(nums, target, cur, 0);
        return res;
        
    }
};
