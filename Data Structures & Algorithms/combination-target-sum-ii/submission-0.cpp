class Solution {
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int target, vector<int>& curr, int start) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            
            if(candidates[i] > target)
                break;
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], curr, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backtrack(candidates, target, curr, 0);
        return ans;
    }
};