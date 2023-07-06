class MyQueue {

    deque<int> D;

public:
    MyQueue() {}
    
    void push(int x) {D.push_back(x);}
    
    int pop()
    {
        int x = D.front();
        D.pop_front();
        return x ;
    }
    
    int peek() {return D.front();}
    
    bool empty() {return D.empty();}
};

