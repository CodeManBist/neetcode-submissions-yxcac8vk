class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> lastIndex;

        for(int i = 0; i < s.size(); i++) {
            lastIndex[s[i]] = i;
        }

        int i = 0;

        while(i < s.size()) {
            int start = i;
            int end = lastIndex[s[i]];

            while(i < end) {
                end = max(end, lastIndex[s[i]]);
                i++;
            }

            res.push_back(end - start + 1);
            i++;
        }

        return res;
    }
};
