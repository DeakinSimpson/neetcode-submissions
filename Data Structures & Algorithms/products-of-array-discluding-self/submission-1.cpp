class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // create the output array (the same size as the input array)
        std::vector<int> output(nums.size());
        std::vector<int> prefix(nums.size());
        std::vector<int> suffix(nums.size());

        int n { static_cast<int>(nums.size()) };

        // create the prefix array
        int prefixTotal { 1 };
        for (int i {}; i < n; ++i) {
            prefixTotal *= nums[i];
            prefix[i] = prefixTotal;
        }
        
        // create the suffix array
        int suffixTotal { 1 };
        for (int i { n - 1 }; i >= 0; --i) {
            suffixTotal *= nums[i];
            suffix[i] = suffixTotal;
        }

        for (int i {}; i < n; ++i) {
            int p {};
            int s {};

            (i == 0) ? p = 1 : p = prefix[i - 1];
            (i == n - 1) ? s = 1 : s = suffix[i + 1];

            output[i] = p * s;
        }

        return output;
    }
};
