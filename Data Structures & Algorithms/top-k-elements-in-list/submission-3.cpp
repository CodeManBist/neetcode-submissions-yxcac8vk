class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int num: nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto &it: mp) {
            pq.push({ it.second, it.first });
        }

        vector<int> ans;

        int i = 0;
        while(i < k) {
            auto p = pq.top();
            ans.push_back(p.second);
            pq.pop();
            i++;
        }

        return ans;
    }
};
