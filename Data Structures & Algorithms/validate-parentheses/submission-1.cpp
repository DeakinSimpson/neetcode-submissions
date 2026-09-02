class Solution {
public:
    bool isValid(string s) {
        std::stack<char> b;
        std::unordered_map<char, char> closeOpen {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        // loop through each char in the string
        for (char c : s) {
            // if close bracket
            if (closeOpen.count(c)) { // if c exists as a key in the hash (is close)
                // if stack is  NOT empty
                // if top of stack is open bracket
                if (!b.empty() && b.top() == closeOpen[c]) { // make sure top is the same open bracket
                    // pop open bracket
                    b.pop();
                } else {
                    // stack is either empty or has different close bracket
                    return false;
                }
            } else {
                b.push(c);
            }
            // if open bracket
                // push to stack
        }
        // if stack is not empty then there was left over open brackets
        return b.empty();

    }
};
