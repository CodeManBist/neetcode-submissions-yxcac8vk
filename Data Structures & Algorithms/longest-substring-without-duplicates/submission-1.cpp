class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int left = 0, right = 0;
        int ans = 0;

        while(right < s.size()) {

            while(mp.find(s[right]) != mp.end()) {
                mp.erase(s[left]);
                left++;
            }

            mp[s[right]]++;

            int length = right - left + 1;
            ans = max(ans, length);

            right++;
        }

        return ans;
    }
};
