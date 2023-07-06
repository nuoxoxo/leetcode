class MyStack {
    
private:
    queue<int>  Q;

public:
    MyStack() { }
    
    void push(int x) {
        int     i;

        Q.push(x);
        i = -1;
        while (++i < Q.size() - 1)
        {
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    int pop() {
        int     res = Q.front();
        Q.pop();
        return res ;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return (!(Q.size()));
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
