#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n { static_cast<int>(nums.size()) };
        std::unordered_map<int, int> hm;

        for (int i {}; i < n; ++i) {
            int difference = target - nums[i];
            if (hm.find(difference) != hm.end()) {
                return { hm[difference], i };
            }

            hm.insert({nums[i], i});
        }
        return {};
    }
};
