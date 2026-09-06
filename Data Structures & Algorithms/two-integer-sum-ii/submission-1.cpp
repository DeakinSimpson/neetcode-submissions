class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i {}, j {static_cast<int>(numbers.size()) - 1}; (i < numbers.size() && j >=0);) {
            if (numbers[i] + numbers[j] > target) { --j; }
            if (numbers[i] + numbers[j] < target) { ++i; }
            if (numbers[i] + numbers[j] == target) { return {i + 1, j + 1}; }
        }

        return {};
    }
};
