class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        int left = 0, right = 0;

        unordered_map<int, int> mp1;

        for(int i = 0; i < s1.size(); i++) {
            mp1[s1[i]]++;
        }

        unordered_map<int, int> mp2;

        while(right < s2.size()) {
            
            mp2[s2[right]]++;

            int windowSize = right - left + 1;

            if(windowSize > s1.size()) {
                mp2[s2[left]]--;

                if(mp2[s2[left]] == 0) {
                    mp2.erase(s2[left]);
                }
                left++;
            }

            if(mp1 == mp2) {
                return true;
            }

            right++;
        }
        return false;
    }
};
