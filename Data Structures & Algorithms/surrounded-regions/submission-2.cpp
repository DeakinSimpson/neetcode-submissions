class Solution {
    std::vector<std::pair<int, int>> dirs {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board)
    {
        const std::size_t ROWS { board.size() };
        const std::size_t COLS { board[0].size() };

        // std::vector<std::vector<bool>> isO(ROWS, std::vector<bool>(COLS, true));
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        std::queue<std::pair<int, int>> q;

        for (auto c {0uz}; c < COLS; ++c)
        {
            if (board[0][c] == 'O') { q.push(std::make_pair(0, c)); }
            if (board[ROWS - 1][c] == 'O') { q.push(std::make_pair(ROWS - 1, c)); }
        }

        for (auto r {0uz}; r < ROWS; ++r)
        {
            if (board[r][0] == 'O') { q.push(std::make_pair(r, 0)); }
            if (board[r][COLS - 1] == 'O') { q.push(std::make_pair(r, COLS - 1)); }
        }

        bfs(q, board, visited);

        for (auto r {0uz}; r < ROWS; ++r)
        {
            for (auto c {0uz}; c < COLS; ++c)
            {
                if (!visited[r][c])
                {
                    board[r][c] = 'X';
                }
            }
        }
    }

    void bfs(std::queue<std::pair<int, int>>& q,
        std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited)
    {
        const std::size_t ROWS { board.size() };
        const std::size_t COLS { board[0].size() };

        while (!q.empty())
        {
            auto [r, c] { q.front() };
            q.pop();
            visited[r][c] = true;

            for (auto [dr, dc] : dirs)
            {
                int nr { r + dr };
                int nc { c + dc };

                if (nr > 0 && nr < ROWS && nc > 0 && nc < COLS 
                    && board[nr][nc] == 'O' && !visited[nr][nc])
                {
                    visited[nr][nc] = true;
                    q.push(std::make_pair(nr, nc));
                }
            }
        }
    }
};
