class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;

        int maxLength = 0;
        int j = 0;
        
        for(int i = 0; i < s.size(); i++) {

            while(charSet.find(s[i]) != charSet.end()) {
                charSet.erase(s[j]);
                j++;
            }
            charSet.insert(s[i]);
            maxLength = max(maxLength, i - j + 1);
        }
        return maxLength;
    }
};
