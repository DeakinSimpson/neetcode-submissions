#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    std::string sortString(std::string s) {
        std::sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // make a hashmap of sorted strings with their index in the output vector
        std::vector<std::vector<std::string>> output {};
        std::unordered_map<std::string, int> anagramIndexes;
        int n { static_cast<int>(strs.size()) };

        for (int i {}; i < n; ++i) {
            // get the sorted string
            std::string sorted { sortString(strs[i]) };

            // check if the sorted string is in the hashmap
                // if it is push back to the output vector the location stored in the hash

                // if not append the new string to the hashmap and the index of the vector
            if (anagramIndexes.find(sorted) != anagramIndexes.end()) {
                output[anagramIndexes[sorted]].push_back(strs[i]);
            } else {
                anagramIndexes.insert({sorted, output.size()});
                output.push_back({strs[i]});
            }
        }

        return output;
    }
};
