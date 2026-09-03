class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> nums{};

        for (const std::string& token : tokens) {
            // if the token is a operand, perform operation
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int output;
                // get the second value
                int second { nums.top() };
                nums.pop();

                // get the first value
                int first { nums.top() };
                nums.pop();

                // perform operation
                if (token == "+") { output = first + second; }
                if (token == "-") { output = first - second; }
                if (token == "*") { output = first * second; }
                if (token == "/") { output = first / second; }

                // push back to heap for next operation
                nums.push(output);
            } else {
                nums.push(std::stoi(token));
            }
        }

        return nums.top();
    }
};
