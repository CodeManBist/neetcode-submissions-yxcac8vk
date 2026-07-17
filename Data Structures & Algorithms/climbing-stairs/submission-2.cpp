class Solution {
public:
    int memoWays(int n, vector<int>& dp) {
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        dp[n] = memoWays(n-1, dp) + memoWays(n-2, dp);

        return dp[n];
    }


    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

        return memoWays(n, dp);
    }
};
