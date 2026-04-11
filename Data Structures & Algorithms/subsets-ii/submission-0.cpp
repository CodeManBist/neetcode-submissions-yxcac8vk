class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& curr, int idx, vector<vector<int>>& ans) {

        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // 1️⃣ INCLUDE nums[idx]
        curr.push_back(nums[idx]);
        getAllSubsets(nums, curr, idx + 1, ans);
        curr.pop_back();

        // 2️⃣ EXCLUDE nums[idx]
        // Skip all future duplicates
        int nextIdx = idx;
        while (nextIdx + 1 < nums.size() && nums[nextIdx] == nums[nextIdx + 1])
            nextIdx++;

        getAllSubsets(nums, curr, nextIdx + 1, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;

        getAllSubsets(nums, curr, 0, ans);
        return ans;
    }
};
