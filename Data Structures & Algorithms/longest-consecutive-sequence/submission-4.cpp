class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxStreak = 1;
        int currentStreak = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) continue;

            if(nums[i] - nums[i-1] == 1) {
                currentStreak++;
            } else {
                currentStreak = 1;
            }

            maxStreak = max(maxStreak, currentStreak);
        }

        return maxStreak;
    }
};
