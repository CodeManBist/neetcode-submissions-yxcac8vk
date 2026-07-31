class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixArr(n, 1);
        vector<int> suffixArr(n, 1);

        //build prefix
        int prefix = 1;
        for(int i = 1; i < n; i++) {
            prefix *= nums[i-1];
            prefixArr[i] = prefix;
        }

        //build suffix
        int suffix = 1;
        for(int i = n-2; i >= 0; i--) {
            suffix *= nums[i + 1];
            suffixArr[i] = suffix;
        }

        //final answer
        vector<int> ans(n, 1);

        for(int i = 0; i < n; i++) {
            ans[i] = prefixArr[i] * suffixArr[i];
        }

        return ans;
    }
};
