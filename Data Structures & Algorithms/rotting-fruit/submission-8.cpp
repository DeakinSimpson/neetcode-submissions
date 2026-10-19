class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        using Coord = std::pair<std::size_t, std::size_t>;

        const auto ROWS { grid.size() };
        const auto COLS { grid[0].size() };
        constexpr int EMPTY { 0 };
        constexpr int FRESH { 1 };
        constexpr int ROTTEN { 2 };


        // create fruit counnt and set to 0
        int fruitCount { 0 };

        // create q of coords to visit
        std::queue<std::pair<Coord, int>> q;

        // create visited fruit count
        int visitedFruitCount { 0 };

        // loop through all positions
        for (auto r {0uz}; r < ROWS; ++r)
        {
            for (auto c {0uz}; c < COLS; ++c)
            {
                // if the fruit is fresh
                if (grid[r][c] == FRESH)
                {
                    // add to fruit count
                    ++fruitCount;
                }

                // if the fruit is rotten
                if (grid[r][c] == ROTTEN)
                {
                    // push coord to the q
                    q.push(std::make_pair(std::make_pair(r, c), 0));
                    ++fruitCount;
                    ++visitedFruitCount;
                }
            }
        }    

        // create maxTime and set to 0
        int maxTime { 0 };

        std::vector<std::vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // while q is not empty
        while (!q.empty())
        {
            // pop the front of the q
            auto [coord, time] { q.front() };
            auto [cur_row, cur_col] { coord };
            q.pop();

            // if nei time > maxTime then maxTime = nei time
            if (time > maxTime)
            {
                maxTime = time;
            }

            // add all neighbors that are fruit to the q
            for (int i {}; i < 4; ++i)
            {
                // set nei value to cur value + 1
                std::size_t nei_row { cur_row + dirs[i][0] };
                std::size_t nei_col { cur_col + dirs[i][1] };

                if (nei_row < 0 || nei_row >= ROWS || nei_col < 0 
                    || nei_col >= COLS || grid[nei_row][nei_col] != FRESH)
                {
                    continue;
                }

                q.push(std::make_pair(std::make_pair(nei_row, nei_col), time + 1));
                grid[nei_row][nei_col] = -1;

                // increment visited fruit count
                ++visitedFruitCount;
            }
        }

        std::cout << "fruit: " << fruitCount << ", visited fruit: " << visitedFruitCount;

        // if the visited fruit count != fruit count
        if (visitedFruitCount < fruitCount)
        {
            // return -1
            return -1;
        }

        // return max time
        return maxTime;
    }
};
