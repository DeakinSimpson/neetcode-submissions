class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        std::unordered_set<int> vals;

        for (auto num : nums)
        {
            if (vals.contains(num))
            {
                return true;
            }

            vals.insert(num);
        }

        return false;
    }
};