class Solution {
public:
    std::vector<int> cache;
    int maxProduct(vector<int>& nums)
    {
        int res = nums[0];

        int curMin { 1 };
        int curMax { 1 };

        for (int num : nums)
        {
            int tmp { curMax * num };
            curMax = std::max(std::max(num * curMax, num * curMin), num);
            curMin = std::min(std::min(tmp, num * curMin), num);

            res = std::max(res, curMax);
        }

        return res;
    }
};
