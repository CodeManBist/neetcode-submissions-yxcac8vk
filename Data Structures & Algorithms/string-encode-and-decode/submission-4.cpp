class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string str: strs) {
            int size = str.size();
            encoded += to_string(size);
            encoded += "#";
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') {
                j++;
            }

            string len = s.substr(i, j - i);
            int size = stoi(len);

            j++;

            string word = s.substr(j, size);

            decoded.push_back(word);

            i = j + size;
        }
        return decoded;
    }
};
