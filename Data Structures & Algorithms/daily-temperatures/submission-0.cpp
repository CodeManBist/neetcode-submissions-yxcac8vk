class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            int curr = temperatures[i];
            int j = i + 1;
            int days = 0;

            while(j < n) {
                days++;

                if(temperatures[j] > curr) {
                    ans[i] = days;
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};
