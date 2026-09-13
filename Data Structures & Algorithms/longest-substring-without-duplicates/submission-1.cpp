class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l {};
        std::unordered_set<char> cmap {};
        int size {};
        int n { static_cast<int>(s.size()) };

        for (int r {}; r < n; ++r)
        {
            while(cmap.find(s[r]) != cmap.end())
            {
                cmap.erase(s[l]);
                ++l;
            }
            cmap.insert(s[r]);
            size = std::max(size, r - l + 1);
            
        }

        return size;
    }
};
