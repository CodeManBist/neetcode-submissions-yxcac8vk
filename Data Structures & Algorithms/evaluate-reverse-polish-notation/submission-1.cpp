class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();

                if(token == "+") s.push(op1 + op2);
                if(token == "-") s.push(op1 - op2);
                if(token == "*") s.push(op1 * op2);
                if(token == "/") s.push(op1 / op2);
            }else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
