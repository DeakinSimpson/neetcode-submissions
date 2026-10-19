class Solution {
public:
    using position_type = std::optional<std::pair<int, int>>;
    static constexpr int INF { 2147483647 };

    std::size_t GRID_ROWS {0};
    std::size_t GRID_COLS {0};

    void islandsAndTreasure(vector<vector<int>>& grid)
    {
        const auto ROWS { grid.size() };
        const auto COLS { grid[0].size() };

        // first start by adding each treasure to the queue
        std::queue<std::pair<int, int>> q;
        for (auto r {0uz}; r < ROWS; ++r)
        {
            for (auto c {0uz}; c < COLS; ++c)
            {
                if (grid[r][c] == 0)
                {
                    q.push(std::make_pair(r, c));
                }
            }
        }

        std::vector<std::vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        while (!q.empty())
        {
            // get the coord at the front
            auto [row, col] { q.front() };
            q.pop();

            // for each neighbor
            for (int i = 0; i < 4; ++i)
            {
                // get the current direction
                int r { row + dirs[i][0] };
                int c { col + dirs[i][1] };

                // if nei is out of bounds or != INF skip
                if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != INF)
                {
                    continue;
                }

                // the value of treasure is 0, if this werent the case 
                // we could just set it to 0 in the initial push loop
                grid[r][c] = grid[row][col] + 1;
                q.push(std::make_pair(r, c));
            }
        }
    }
};
