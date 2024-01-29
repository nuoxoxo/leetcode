class MyQueue {

vector<int> vec;

public:
    MyQueue() {
        // left blank
    }
    
    void push(int x) {
        vec.push_back(x);
    }
    
    int pop() {
        assert( ! empty());
        int res = vec[0];
        vec.erase( vec.begin() );
        return res;
    }
    
    int peek() {
        assert( ! empty() );
        return vec[0];
    }
    
    bool empty() {
        return (!vec.size());
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
