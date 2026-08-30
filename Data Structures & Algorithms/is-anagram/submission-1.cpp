#include <unordered_map>

class Solution {
public:
    void getHashmap(
        const string& string, 
        std::unordered_map<char, int>& output) {
        
        for (char c : string) {
            output[c] += 1;
        }
    }

    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        getHashmap(s, s_map);
        getHashmap(t, t_map);

        for (auto pair : s_map) {
            if (s_map.size() != t_map.size() 
                || t_map.find(pair.first) == t_map.end()
                || s_map[pair.first] != t_map[pair.first] ) { return false; }
        }

        return true;
    }
};
