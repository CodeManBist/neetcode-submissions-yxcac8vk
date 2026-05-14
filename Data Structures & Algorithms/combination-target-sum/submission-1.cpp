class Solution {
public:
    void solve(int idx, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& temp, int sum) {
        if(sum == target) {
            ans.push_back(temp);
            return;
        }

        if(idx >= nums.size() || sum > target) {
            return;
        }

        temp.push_back(nums[idx]);

        solve(idx, nums, target, ans, temp, sum + nums[idx]);

        temp.pop_back();

        solve(idx + 1, nums, target, ans, temp, sum);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, target, ans, temp, 0);

        return ans;
    }
};
