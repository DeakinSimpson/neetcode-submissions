class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a frequency hashmap
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num] += 1;
        }
        // create a vector of buckets that hold the frequencies
        // this is the size of the frequency hashmap
        std::vector<std::vector<int>> freq(nums.size() + 1);
        
        for (const auto& pair : count) {
            freq[pair.second].push_back(pair.first);
        }

        std::vector<int> output;
        for (int i {static_cast<int>(freq.size() - 1)}; i > 0; --i) {
            for (int n : freq[i]) {
                output.push_back(n);
                if (output.size() >= k) { return output; }
            }
        }

        return output;
    }
};
