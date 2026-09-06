class Solution {
public:
    bool isPalindrome(string s) {
        for (
            int i {}, j {static_cast<int>(s.size())};
            (i < s.size()) && (j >= 0);
        ) {
            if (!std::isalnum(s[i])) {++i; continue;}
            if (!std::isalnum(s[j])) {--j; continue;}
            if (std::tolower(s[i]) != std::tolower(s[j])) { return false; }
            ++i;
            --j;
        }

        return true;
    }
};
