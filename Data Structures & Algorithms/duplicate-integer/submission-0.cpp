#include <unordered_map>
#include <iostream>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> vals {};
        for (int num : nums) {
            vals[num] += 1;
            if (vals[num] >= 2) { return true; }
        }
        return false;
    }
};