class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<std::vector<int>> res = {{}};

        for (int num : nums)
        {
            int size = res.size();

            for (auto i {0uz}; i < size; ++i)
            {
                std::vector<int> subset = res[i];

                subset.push_back(num);
                res.push_back(subset);
            }
        }

        return res;
    }
};
