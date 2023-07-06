class MyCircularQueue {

vector<int> dq;
int curr, len, K;

public:
    MyCircularQueue(int k)
    :
    dq(vector<int>(k)),
    curr(0),
    len(0),
    K(k)
    {
    }
    
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        dq[(curr + len) % K] = value;
        ++len;
        return true;
    }
    
    bool deQueue()
    {
        if (isEmpty())
            return false;
        curr = (curr + 1) % K;
        --len;
        return true;
    }
    
    int Front()
    {
        if (isEmpty())
            return -1;
        return dq[curr];
    }
    
    int Rear()
    {
        if (isEmpty())
            return -1;
        int dest = curr + len - 1;
        return dq[dest % K];
    }
    
    bool isEmpty()
    {
        return ( !len);
    }
    
    bool isFull()
    {
        return (K == len);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
