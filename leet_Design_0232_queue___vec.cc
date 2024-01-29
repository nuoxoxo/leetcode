class MyQueue {

vector<int> vec;

public:
    MyQueue() {
        // left blank
    }
    
    void push(int x) {
        this->vec.push_back(x);
    }
    
    int pop() {
        assert( ! empty());
        int res = this->vec[0];
        this->vec.erase( this->vec.begin() );
        return res;
    }
    
    int peek() {
        assert( ! empty() );
        return this->vec[0];
    }
    
    bool empty() {
        return (!this->vec.size());
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
