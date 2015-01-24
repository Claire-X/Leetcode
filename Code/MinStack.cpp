class MinStack {
public:
    void push(int x) {
        if(stk.empty()||min.top()>=x) min.push(x);
        stk.push(x);
    }

    void pop() {
        if(min.top()==stk.top()) min.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min.top();    
    }
private:
    stack<int> stk;
    stack<int> min;
};
