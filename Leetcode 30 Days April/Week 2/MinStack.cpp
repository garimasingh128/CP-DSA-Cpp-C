class MinStack {
    stack<int> s;
    stack<int> p;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if(s.empty())
        {
            s.push(x);
            p.push(x);
        }
        else
        {
            if(p.top()>=x)
                p.push(x);
            s.push(x);
        }

    }

    void pop() {
        if(s.top()==p.top())
            p.pop();
        s.pop();

    }

    int top() {

        return s.top();

    }

    int getMin() {

        return p.top();

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
