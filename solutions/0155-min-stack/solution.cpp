class MinStack {
public:
    vector<int> v;
    vector<int> mini;
    MinStack() {

    }
    
    void push(int val) {
        v.push_back(val);
        if(mini.empty() || val <= mini.back()) mini.push_back(val);
    }
    
    void pop() {
        if(!mini.empty() && v.back() == mini.back()) mini.pop_back();
        if(!v.empty()) v.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return mini.back();
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
