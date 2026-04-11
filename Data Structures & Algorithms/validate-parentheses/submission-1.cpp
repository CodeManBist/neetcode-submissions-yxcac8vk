class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;

        stack<char> st;

        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);  // Push if opening bracket
            } else {
                if(st.empty()) return false;  // No matching opening bracket
                
                char top = st.top();
                if((c == ')' && top == '(') ||
                   (c == '}' && top == '{') ||
                   (c == ']' && top == '[')) {
                    st.pop();  // Pop if matching
                } else {
                    return false;  // Invalid if not matching
                }
            }
        }
        
        return st.empty(); // Check if all brackets matched
    }
};
