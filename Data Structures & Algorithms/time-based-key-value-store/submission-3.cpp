using Key = std::string;
using Value = std::string;
using Timestamp = int;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& pairs { map_[key] };
        pairs.push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!map_.contains(key)) { return ""; }

        auto& pairs { map_[key] };

        int l { 0 };
        int r { static_cast<int>(pairs.size()) - 1 };
        std::string o { "" };

        while (l <= r)
        {
            int m { l + (r - l) / 2 };

            if (pairs[m].first <= timestamp)
            {
                o = pairs[m].second;
                l = m + 1;
            } else
            {
                r = m - 1;
            }
        }

        return o;
    }

private:
    std::unordered_map<Key, std::vector<std::pair<int, std::string>>> map_;
};
