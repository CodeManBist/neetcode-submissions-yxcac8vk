class Solution {
public:
    void solve(int idx, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(idx >= nums.size() || target < 0) {
            return;
        }

        temp.push_back(nums[idx]);

        solve(idx, nums, target - nums[idx], ans, temp);

        temp.pop_back();

        solve(idx + 1, nums, target, ans, temp);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, target, ans, temp);

        return ans;
    }
};
