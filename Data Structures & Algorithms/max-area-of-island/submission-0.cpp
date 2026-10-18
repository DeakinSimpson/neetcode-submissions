class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        // create int maxIslandSize
        int maxIslandSize { 0 };

        const auto rows { grid.size() };
        const auto cols { grid[0].size() };

        // loop through all of the grid
        for (auto i {0uz}; i < rows; ++i)
        {
            for (auto j {0uz}; j < cols; ++j)
            {
                // if grid[i][j]
                if (grid[i][j] == 1)
                {
                    // maxIslandSize = std::max(bfs, maxIslandSize)
                    maxIslandSize = std::max(bfs(grid, i, j), maxIslandSize);
                }
            }
        }
        // return max island size
        return maxIslandSize;
    }

    int bfs(std::vector<std::vector<int>>& grid, int _i, int _j)
    {
        // create an int of the island size
        int islandSize {};

        // create a queue of the nodes to visit
        std::queue<std::pair<int, int>> q;

        // add grid[_i][_j]
        q.push(std::make_pair(_i, _j));
        
        // set grid[_i][_j] == 0
        grid[_i][_j] = 0;

        const auto rows { grid.size() - 1 };
        const auto cols { grid[0].size() - 1 };

        // while queue is not empty
        while (!q.empty())
        {
            // pop the front of the queue
            auto [i, j] { q.front() };
            q.pop();

            // add 1 to the island size
            ++islandSize;

            if (i > 0 && grid[i - 1][j] == 1) 
            { 
                q.push(std::make_pair(i - 1, j));
                grid[i - 1][j] = 0;
            }
            if (i < rows && grid[i + 1][j])
            {
                q.push(std::make_pair(i + 1, j));
                grid[i + 1][j] = 0;
            }
            if (j > 0 && grid[i][j - 1])
            {
                q.push(std::make_pair(i, j - 1));
                grid[i][j - 1] = 0;
            }
            if (j < cols && grid[i][j + 1])
            {
                q.push(std::make_pair(i, j + 1));
                grid[i][j + 1] = 0;
            }
        }
        return islandSize;
    }
};
