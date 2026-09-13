class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLen { static_cast<int>(matrix[0].size()) };
        int colLen { static_cast<int>(matrix.size()) };

        int min { 0 };
        int max { rowLen * colLen - 1 };

        while (min <= max) {
            int mid { min + (max - min) / 2 };
            int v { matrix[mid / rowLen][mid % rowLen] };
            if (v == target) { return true; }
            if (v < target) { min = mid + 1; }
            if (v > target) { max = mid - 1; }
        }

        return false;
    }
};
