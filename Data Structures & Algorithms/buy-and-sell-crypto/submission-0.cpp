class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest { prices[0] };
        int best { 0 };

        for (auto& price : prices)
        {
            if (price - lowest > best)
            {
                best = price - lowest;
            }

            if (price < lowest)
            {
                lowest = price;
            }
        }

        return best;
    }
};
