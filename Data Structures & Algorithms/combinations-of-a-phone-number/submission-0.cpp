class Solution {
public:
    unordered_map<char, string> mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
    };
    vector<string> result;

    void getAllComb(string digits, int index, string& curr) {
        if(index == digits.size()) {
            result.push_back(curr);
            return;
        }

        string letters = mp[digits[index]];

        for(char c : letters) {
            curr.push_back(c);
            getAllComb(digits, index+1, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        string curr = "";
        getAllComb(digits, 0, curr);
        return result;
    }
};