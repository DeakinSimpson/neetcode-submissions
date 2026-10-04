class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        using Distance = double;
        using Point = std::tuple<Distance, int, int>;
        std::priority_queue<Point, std::vector<Point>, std::greater<Point>> q;

        for (auto point : points)
        {
            Distance d { std::sqrt(std::pow(point[0], 2) + std::pow(point[1],2)) };
            
            q.push(std::make_tuple(d, point[0], point[1]));
        }

        std::vector<std::vector<int>> res;

        for (auto i {0}; i < k; ++i)
        {
            auto [_, x, y] { q.top() };
            q.pop();

            res.push_back({x, y});
        }

        return res;
    }
};
