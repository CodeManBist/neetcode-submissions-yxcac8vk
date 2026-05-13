class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;

        for(int i = 0; i < n; i++) {
            
            if(tokens[i] == "+" ||
               tokens[i] == "-" ||
               tokens[i] == "*" ||
               tokens[i] == "/") {
                int op1 = s.top();
                s.pop();
                
                int op2 = s.top();
                s.pop();

                int result;

                if(tokens[i] == "+") {
                    result = op2 + op1;
                } else if(tokens[i] == "-") {
                    result = op2 - op1;
                } else if(tokens[i] == "*") {
                    result = op2 * op1;
                } else {
                    result = op2 / op1;
                }
                    s.push(result);
                } 
                else {
                    s.push(stoi(tokens[i]));
                }
            }
        return s.top();
    }
};
