class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        mp[key].push_back({ value, timestamp });
    }
    
    string get(string key, int timestamp) {
        string ans;
        int st = 0, end = mp[key].size() - 1;

        while(st <= end) {
            int mid = (st + end) / 2;

            if(mp[key][mid].second <= timestamp) {
                ans = mp[key][mid].first;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
