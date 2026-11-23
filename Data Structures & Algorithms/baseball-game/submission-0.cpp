class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        const auto n { operations.size() };
        std::vector<int> record;
        int idx { -1 };  /* running idx of record */

        for (auto i {0uz}; i < n; ++i)
        {
            if (operations[i] == "C") 
            { 
                record.pop_back(); 
                --idx; 
                continue;
            }
            if (operations[i] == "+") 
            {
                record.push_back(record[idx] + record[idx - 1]);
                ++idx;
                continue;
            }
            if (operations[i] == "D")
            {
                record.push_back(2 * record[idx]);
                ++idx;
                continue;
            }
            
            record.push_back(std::stoi(operations[i]));
            ++idx;
        }

        int sum {};
        for (auto r : record)
        {
            sum += r;
        }

        return sum;
    }
};