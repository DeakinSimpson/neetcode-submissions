#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encodedString;

        for (std::string str : strs) {
            int length { static_cast<int>(str.size()) };
            encodedString += std::to_string(length) + "#" + str;
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        int i { 0 };
        std::vector<std::string> decodedString;

        // loop through the string
        while (i < s.size()) {
            int j = i;
            // look for the # value
            while (s[j] != '#') {
                ++j;
            }
            // now that you have the start and end index of the length, get length
            int length { std::stoi(s.substr(i, j - i)) };
            i = j + 1; // place the index just after the #
            j = i + length; // place j at the end of the word (found by length)
            decodedString.push_back(s.substr(i, length));
            i = j; // place i with j (ready for next number)
        }
        return decodedString;
    }
};
