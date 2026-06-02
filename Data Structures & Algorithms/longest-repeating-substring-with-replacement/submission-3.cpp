class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        int left = 0, right = 0;
        int maxCount = 0;

        while(right < s.size()) {
            int windowSize = right - left + 1;

            mp[s[right]]++;

            maxCount = max(maxCount, mp[s[right]]);

            if(windowSize - maxCount <= k) {
                ans = windowSize;
            } else {
                mp[s[left]]--;
                left++;
            }
            right++;
        }

        return ans;
    }
};
