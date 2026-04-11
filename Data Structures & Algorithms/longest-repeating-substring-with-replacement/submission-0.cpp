class Solution {
public:
    int characterReplacement(string s, int k) {
        int counts[26] = {0};
        int maxFreq = 0, maxLength = 0;
        int j = 0;

        for(int i = 0; i < s.size(); i++) {
            counts[s[i] - 'A']++;
            maxFreq = max(maxFreq, counts[s[i] - 'A']);

            if((i - j + 1) - maxFreq > k) {
                counts[s[j] - 'A']--;
                j++;
            }
            maxLength = max(maxLength, i - j + 1);
        }
        return maxLength;
    }
};
