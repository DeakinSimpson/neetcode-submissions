class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        std::priority_queue<int> maxHeap;

        for (int stone : stones)
        {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1)
        {
            int x { maxHeap.top() };
            maxHeap.pop();

            int y { maxHeap.top() };
            maxHeap.pop();

            if (x == y) { continue; }

            maxHeap.push(std::abs(x - y));
        }

        maxHeap.push(0);
        return maxHeap.top();
    }
};
