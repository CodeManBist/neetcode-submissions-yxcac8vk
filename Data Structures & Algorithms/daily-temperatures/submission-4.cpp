class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n, 0);
        stack<pair<int, int>> s;


        for(int i = 0; i < n; i++) {
    
            while(!s.empty() && temperatures[i] > s.top().first) {
                int index = s.top().second;
                s.pop();

                ans[index] = i - index;
            }
            s.push(make_pair(temperatures[i], i));
        }
        return ans;
    }
};
