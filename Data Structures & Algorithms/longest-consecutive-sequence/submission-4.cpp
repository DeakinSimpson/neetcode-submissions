#include <algorithm>

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> numsD;
        int output { 0 };

        // loop through all nums
        for (int num : nums) {
            // if the num does not exist in the hashmap already
            if (!numsD[num]) {
                // the length at num is the length of the previous and next + 1
                numsD[num] = numsD[num - 1] + numsD[num + 1] + 1;
                // update the length value at the start and end of the chain
                // this is so if another number is added it can be linked to the chain
                numsD[num - numsD[num - 1]] = numsD[num];
                numsD[num + numsD[num + 1]] = numsD[num];

                // set the new max to the max between the current max and the current longest
                output = std::max(output, numsD[num]);
            }
        }

        return output;
    }
};
