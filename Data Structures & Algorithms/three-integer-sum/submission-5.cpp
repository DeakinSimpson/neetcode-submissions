#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // creat the output vector oVec
        std::vector<std::vector<int>> oVec {};

        // sort the array
        std::sort(nums.begin(), nums.end());

        for (int i {}; i < nums.size() - 2; ++i) {
            // skip if the previous i value is the same, this avoids the duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l { i + 1 };
            int r { static_cast<int>(nums.size()) - 1 };

            while (l < r) {
                if (nums[l] + nums[r] == -nums[i]) {
                    oVec.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
                if (nums[l] + nums[r] < -nums[i]) { ++l; }
                if (nums[l] + nums[r] > -nums[i]) { --r; }
            }
        }

        return oVec;
    }
};
