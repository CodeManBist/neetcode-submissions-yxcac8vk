class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(char ch : s) {
            if(ch =='('||
               ch =='['||
               ch =='{') {
                S.push(ch);
               }else {
                if(S.empty()) return false;

                if((ch == ')' && S.top() == '(') ||
                   (ch == ']' && S.top() == '[') ||
                   (ch == '}' && S.top() == '{') ) {
                    S.pop();
                   }else {
                    return false;
                   }
               }
        }
        return S.empty();
    }
};
