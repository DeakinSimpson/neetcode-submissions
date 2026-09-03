class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> tempDec{};
        std::stack<int> inx{};
        std::vector<int> result(temperatures.size());

        // loop through each temp
        int n { static_cast<int>(temperatures.size()) };
        for (int i{}; i < n; ++i) {
            // if the temp is larger then the previous |  
            while (!tempDec.empty() && tempDec.top() < temperatures[i]) {
                // add the difference
                result[inx.top()] = i - inx.top();

                // pop the smaller value
                tempDec.pop();
                inx.pop();
            }

            tempDec.push(temperatures[i]);
            inx.push(i);
        }

        return result;
    }
};
