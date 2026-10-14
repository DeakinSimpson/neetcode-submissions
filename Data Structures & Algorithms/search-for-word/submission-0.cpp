class Solution {
public:
    int numOfRows {};
    int numOfCols {};
    std::set<std::pair<int, int>> visited;

    bool exist(vector<vector<char>>& board, string word)
    {
        numOfRows = board.size();
        numOfCols = board[0].size();

        for (int r {}; r < numOfRows; ++r)
        {
            for (int c {}; c < numOfCols; ++c)
            {
                if (backtrack(board, word, r, c, 0))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtrack(
        std::vector<std::vector<char>>& board,
        std::string word,
        int row, int col, int curWordLength)
    {
        // if out current word length == target word length, then they are equal
        if (curWordLength == word.length())
        {
            return true;
        }

        // if out of bounds or not correct character or already visited return false
        if (row < 0 || col < 0 || row >= numOfRows || col >= numOfCols ||
            board[row][col] != word[curWordLength] || visited.count({row, col}))
        {
            return false;
        }

        // if correct character, continue down branch
        visited.insert({row, col});
        bool result
        {
            backtrack(board, word, row + 1, col, curWordLength + 1) ||
            backtrack(board, word, row - 1, col, curWordLength + 1) ||
            backtrack(board, word, row, col + 1, curWordLength + 1) ||
            backtrack(board, word, row, col - 1, curWordLength + 1)
        };

        visited.erase({row, col});

        return result;
    }
};
