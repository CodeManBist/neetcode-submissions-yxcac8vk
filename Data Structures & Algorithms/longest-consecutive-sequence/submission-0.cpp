class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLength = 0;
        vector<int> sequence;

        for(int num : nums) {
            if(s.find(num - 1) == s.end()) {
                int curr = num;
                int length = 1;

                while(s.find(curr + 1) != s.end()) {
                    curr++;
                    length++;
                }
                if(length > maxLength) {
                    maxLength = length;
                }
            }
        }
        return maxLength;
    }
};
