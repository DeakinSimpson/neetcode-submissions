class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l { 1 };
        int r { *std::max_element(piles.begin(), piles.end()) };
        
        // start best at worst
        int best { r };

        while (l <= r)
        {
            // get the mid point
            int mid { (l + r) / 2 };

            // start total time at 0 for this run
            int totalTime { 0 };

            // loop through each pile in piles
            for (int pile : piles) {
                // addd the total time being the ceiling of pile / mid point
                totalTime += std::ceil(static_cast<double>(pile) / mid);
            }
            // if the total time <= h
            if (totalTime <= h) {
                best = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return best;
    }
};
