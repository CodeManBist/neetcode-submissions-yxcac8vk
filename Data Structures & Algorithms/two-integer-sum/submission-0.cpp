class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++) {
            int b = nums[i];
            int a = target - b;

            if(m.find(a) != m.end()) {
                return {m[a], i};
            }

            m[b] = i;
        }
        return {};
    }
};
