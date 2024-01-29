class MyQueue {

stack<int> stk, tmp;

public:
    MyQueue() {
        // left blank
    }
    
    void push(int x) {
        while ( ! empty()) {
            int temp = stk.top();
            tmp.push(temp);
            stk.pop();
        }
        stk.push(x);
        while ( ! tmp.empty()) {
            int temp = tmp.top();
            stk.push(temp);
            tmp.pop();
        }
    }
    
    int pop() {
        int res = stk.top();
        stk.pop();
        return res;
    }
    
    int peek() {
        return stk.top();
    }
    
    bool empty() {
        return (!stk.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
