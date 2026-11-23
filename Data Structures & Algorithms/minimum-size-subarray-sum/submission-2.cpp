class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int l { 0 };
        int total { 0 };
        int res { INT_MAX };
        const int n = nums.size();

        for (int r {}; r < n; ++r)
        {
            /* add the r num to the running total */
            total += nums[r];

            /* while the total >= target */
            while (total >= target)
            {
                /* the window is the min of current window and min */
                res = std::min(r - l + 1, res);

                /* move l right */
                total -= nums[l];
                ++l;

                /* if the current windows total is still less then target
                   move l right again */
            }
        }

        /* if total was never >= target return 0, else return result */
        return (res == INT_MAX) ? 0 : res;
    }
};