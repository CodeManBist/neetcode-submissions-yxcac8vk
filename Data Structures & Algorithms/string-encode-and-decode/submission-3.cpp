class Solution {
public:

    string encode(vector<string>& strs) {
        string encodeStr="";
        for(int i = 0; i < strs.size(); i++) {
            encodeStr += to_string(strs[i].size()) + "#" + strs[i];
        }
        return encodeStr;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while( i < s.size()) {
            int length = 0;

            while(i < s.size() && s[i] != '#') {
                length = length * 10 + (s[i] -'0');
                i++;
            }
            i++;

            string word = s.substr(i, length);
            ans.push_back(word);

            i += length;
        }
        return ans;
    }
};
