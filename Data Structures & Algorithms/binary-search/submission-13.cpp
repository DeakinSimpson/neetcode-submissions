class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min {};
        int max { static_cast<int>(nums.size())};

        while (min < max) {
            int mid { min + (max - min) / 2 };

            if (nums[mid] >= target) { max = mid; }
            else if (nums[mid] < target) { min = mid + 1; }
            else { return mid; }
        }

        if (min < nums.size() && nums[min] == target) {
            return min;
        }

        return -1;
    }
};
