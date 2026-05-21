class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int num : nums) {
            mp[num]++;
        }

        vector<pair<int, int>> vec;
        for(auto it: mp) {
            vec.push_back({ it.first, it.second});
        }

        sort(vec.begin(), vec.end(),
            [](pair<int, int>& a, pair<int, int>& b) {
                return a.second > b.second;
            });

        for(int i = 0; i < k; i++) {
            ans.push_back(vec[i].first);
        }

        return ans;
    }
};
