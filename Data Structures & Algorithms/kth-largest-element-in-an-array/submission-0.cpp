class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int> q;

        for (auto& num : nums)
        {
            q.push(num);

            if (q.size() > (nums.size() - k + 1))
            {
                q.pop();
            }
        }

        return q.top();
    }
};
