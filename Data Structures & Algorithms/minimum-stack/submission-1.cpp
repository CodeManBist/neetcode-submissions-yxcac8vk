class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    int topIndex = -1;
    MinStack() {
        
    }
    
    void push(int val) {
        topIndex++;
        if(topIndex < stack.size()) {
            stack[topIndex] = val;
        }else {
            stack.push_back(val);
        }

        if(minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if(stack[topIndex] == minStack.back()) {
            minStack.pop_back();
        }
        topIndex--;
    }
    
    int top() {
        return stack[topIndex];    
    }
    
    int getMin() {
        return minStack.back();
    }
};
