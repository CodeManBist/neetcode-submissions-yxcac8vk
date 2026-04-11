class Solution {
public:

    bool isPallindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        return r == s;
    }

    void getAllPalPart(string s, vector<string>& partitions, vector<vector<string>>& ans) {
        if(s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for(int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i+1);
            if(isPallindrome(part)) {
                partitions.push_back(part);
                getAllPalPart(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllPalPart(s, partitions, ans);
        return ans;
    }
};
