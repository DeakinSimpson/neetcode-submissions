class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l {};
        int r { static_cast<int>(heights.size()) - 1 };

        int maxV {};

        while (l < r) {
            int curVol { (std::min(heights[l], heights[r]) * (r - l)) };
            if (curVol > maxV) { maxV = curVol; }
            else if (heights[l] < heights[r]) { ++l; }
            else if (heights[l] > heights[r]) { --r; }
            else { ++l; --r; } 
        }

        return maxV;
    }
};
