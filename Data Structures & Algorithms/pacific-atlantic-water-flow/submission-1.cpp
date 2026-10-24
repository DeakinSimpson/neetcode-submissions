class Solution {
    std::vector<std::pair<int, int>> dirs { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        /*
            imagine that a cell has rain drop on it, mark the cells where the rain will
            flow to both the pacific and the atlantic*/

        // add to q for atl and pac to visit
        std::queue<std::pair<int, int>> atlToVisit {};
        std::queue<std::pair<int, int>> pacToVisit {};

        const std::size_t COLS { heights[0].size() };
        const std::size_t ROWS { heights.size() };
        // push top and bottom
        for (auto i {0uz}; i < COLS; ++i)
        {
            pacToVisit.push(std::make_pair(0, i));
            atlToVisit.push(std::make_pair(ROWS - 1, i));
        }

        // push left and right
        for (auto i {0uz}; i < ROWS; ++i)
        {
            pacToVisit.push(std::make_pair(i, 0));
            atlToVisit.push(std::make_pair(i, COLS - 1));
        }

        // add to q of visited of atl and pac
        std::vector<std::vector<bool>> atl(ROWS, std::vector<bool>(COLS, false));
        std::vector<std::vector<bool>> pac(ROWS, std::vector<bool>(COLS, false));

        // perform bfs on atl
        // prform bfs on pac
        bfs(heights, pacToVisit, pac);
        bfs(heights, atlToVisit, atl);

        std::vector<std::vector<int>> res {};
        // compare to see where they match and push to res

        for (int r {}; r < ROWS; ++r)
        {
            for (int c {}; c < COLS; ++c)
            {
                if (pac[r][c] && atl[r][c])
                {
                    res.push_back({r, c});
                }
            }
        }

        // return res
        return res;
    }



    // bfs
    void bfs(const std::vector<std::vector<int>>& heights, 
        std::queue<std::pair<int, int>>& q, 
        std::vector<std::vector<bool>>& visited)
    {

        // while q not empry
        while (!q.empty())
        {
            auto [r, c] { q.front() };
            q.pop();

            visited[r][c] = true;

            for (auto [dr, dc] : dirs)
            {
                int nr { r + dr };
                int nc { c + dc };

                if (nr >= 0 && nc >= 0 && 
                    nr < heights.size() && nc < heights[0].size() && 
                    !visited[nr][nc] && heights[nr][nc] >= heights[r][c])
                {
                    q.push(std::make_pair(nr, nc));
                }
            }
        }
    }
};