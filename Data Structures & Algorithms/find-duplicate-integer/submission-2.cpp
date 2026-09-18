class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> numsMap;

        int n { static_cast<int>(nums.size()) };
        for (int i {}; i < n; ++i)
        {
            if (numsMap.find(nums[i]) != numsMap.end())
            {
                return nums[i];
            } else 
            {
                numsMap.emplace(nums[i]);
            }
        }

        return 0;
    }
};
