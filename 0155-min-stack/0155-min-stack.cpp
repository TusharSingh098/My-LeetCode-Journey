class MinStack {
private:
    vector<pair<int, int>> stk;

public:
    MinStack() 
    {
        stk.reserve(30000);
    }
    
    void push(int value) {
        if (stk.empty()) stk.emplace_back(value, value);
        else
        {
            int mini{min(stk.back().second, value)};
            stk.emplace_back(value, mini);
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */