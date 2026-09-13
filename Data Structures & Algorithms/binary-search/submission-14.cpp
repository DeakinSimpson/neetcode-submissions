class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min {};
        int max { static_cast<int>(nums.size()) - 1};

        while (min <= max) {
            int mid { min + (max - min) / 2 };

            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        return -1;
    }
};
