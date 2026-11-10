class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;

        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;

            if(s.find(second) != s.end()) {
                return { s[second], i };
            }

            s[first] = i;
        }

        return {};
    }
};
