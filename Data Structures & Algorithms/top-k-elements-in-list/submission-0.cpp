class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> freq;
        for(auto& entry : mp) {
            freq.push_back({entry.first, entry.second});
        }

        sort(freq.begin(), freq.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};
