#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());



        const auto n { nums.size() };

        for (auto i {0uz}; i < n - 2; ++i)
        {
            // nums[i] + nums[j] + nums[k] == 0, therefore:
            // -nums[i] = nums[j] + nums[k]

            if (i > 0 && nums[i] == nums[i - 1]) 
            { 
                continue;
            }

            std::size_t l { i + 1 };
            std::size_t r { n - 1 };

            // while the left pointer is still left of the right pointer
            while (l < r)
            {
                if (-nums[i] == nums[l] + nums[r])
                {
                    res.push_back({ nums[i], nums[l], nums[r] });
                    ++l;
                    --r;

                    // skip duplicate left and right values
                    while (l < r && nums[l] == nums[l - 1]) 
                    { 
                        ++l; 
                    }
                    while (l < r && nums[r] == nums[r + 1]) 
                    { 
                        --r; 
                    }
                }

                // if greater then increase left pointer, vise versa
                if (nums[l] + nums[r] < -nums[i]) 
                { 
                    ++l; 
                }
                if (nums[l] + nums[r] > -nums[i]) 
                { 
                    --r; 
                }
            }
        }

        return res;
    }
};
