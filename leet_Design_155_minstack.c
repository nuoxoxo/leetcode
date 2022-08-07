class MinStack {
public:
    
    deque<int>  st;
    deque<int>  ms;
    
    MinStack() {}

    void push(int val)
    {
        if (st.empty() || val <= ms.front())
            ms.push_front(val);
        st.push_front(val);
    }

    void pop()
    {
        if (ms.front() == st.front())
            ms.pop_front();
        st.pop_front();
    }

    int top()
    {
        return st.front();
    }

    int getMin()
    {
        return ms.front();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
