class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_map<int, int>> rows(9);
        std::vector<std::unordered_map<int, int>> cols(9);
        std::vector<std::unordered_map<int, int>> sqrs(9);


        for (int row {}; row < 9; ++row) {
            for (int col {}; col < 9; ++col) {
                // check if blank
                if (board[row][col] == '.') { continue; }

                // find current square
                int sqr { (3 * (col / 3)) + (row / 3) };
                
                // get the value
                int val { board[row][col] - '0' };

                // add to hashmap
                rows[row][val] += 1;
                cols[col][val] += 1;
                sqrs[sqr][val] += 1;

                // check if hashmap is too large
                if (rows[row][val] > 1 || cols[col][val] > 1 || sqrs[sqr][val] > 1) 
                    { return false; }
            }
        }

        return true;
    }
};
