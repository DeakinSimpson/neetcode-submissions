class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int numIslands { 0 };
        auto height { grid.size() };
        auto width { grid[0].size() };

        for (auto row {0uz}; row < height; ++row)
        {
            for (auto col {0uz}; col < width; ++col)
            {
                // if the location has already been visisted
                if (grid[row][col] == '0') { continue; }

                ++numIslands;
                bfs(grid, row, col);
            }
        }

        return numIslands;
    }

    void bfs(std::vector<std::vector<char>>& grid, std::size_t row, std::size_t col)
    {
        std::queue<std::pair<std::size_t, std::size_t>> q;
        q.push(std::make_pair(row, col));

        auto rowMax { grid.size() - 1 };
        auto colMax { grid[0].size() - 1 };

        while (!q.empty())
        {
            auto [r, c] { q.front() };
            q.pop();

            grid[r][c] = '0';

            if (r > 0 && grid[r - 1][c] == '1') 
            { 
                q.push(std::make_pair(r - 1, c)); 
                grid[r-1][c] = '0';
            }
            if (r < rowMax && grid[r + 1][c] == '1') 
            { 
                q.push(std::make_pair(r + 1, c)); 
                grid[r+1][c] = '0';
            }

            if (c > 0 && grid[r][c - 1] == '1') 
            { 
                q.push(std::make_pair(r, c - 1)); 
                grid[r][c-1] = '0';
            }
            if (c < colMax && grid[r][c + 1] == '1') 
            { 
                q.push(std::make_pair(r, c + 1)); 
                grid[r][c+1] = '0';
            }
        }
    }

    
};
