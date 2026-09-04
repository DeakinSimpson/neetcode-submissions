class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // create vector of pairs speed and position
        std::vector<std::pair<int, int>> pairs {};
        for (int i {}; i < position.size(); ++i) {
            pairs.push_back({ position[i], speed[i] });
        }

        // sort in reverse (sorted by first, breaks ties by second))
        sort(pairs.rbegin(), pairs.rend());

        std::stack<float> time;

        for (const auto& p : pairs) {
            float t { static_cast<float>(target - p.first) / p.second };

            if (time.empty() || t > time.top()) { time.push(t); }
        }

        return time.size();
    }
};
