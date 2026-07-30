class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for(int num: nums) {
            if(s.count(num-1)) continue;

            int length = 1;

            while(s.count(num + 1)) {
                num++;
                length++;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};
