class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        std::vector<int> record;

        for (const auto op : operations)
        {
            if (op == "C") 
            { 
                record.pop_back(); 
            }
            else if (op == "+") 
            {
                const int n = record.size();
                record.push_back(record[n-1] + record[n-2]);
            }
            else if (op == "D")
            {
                record.push_back(2 * record.back());
            }
            else
            {
                record.push_back(std::stoi(op));
            }
        }

        return std::accumulate(record.begin(), record.end(), 0);
    }
};