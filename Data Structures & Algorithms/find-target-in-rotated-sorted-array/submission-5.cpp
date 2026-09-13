class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l { 0 };
        int r { static_cast<int>(nums.size()) - 1 };

        // get the pivot point
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums[m] > nums[r])
            {
                l = m + 1;
            } else
            {
                r = m;
            }
        }

        // reset the values
        int p { l };
        l = 0;
        r = static_cast<int>(nums.size()) - 1;

        // if target is >= pivot and <= right, then we bring l to mid and only search right half
        if (target >= nums[p] && target <= nums[r])
        {
            l = p;
        } else {
            r = p - 1;
        }

        // porform binary serach on the half
        while (l <= r)
        {
            int m { (l + r) / 2 };

            if (nums[m] == target)
            {
                return m;
            } else if (nums[m] < target)
            {
                l = m + 1;
            } else
            {
                r = m - 1;
            }
        }

        return -1;
    }
};
