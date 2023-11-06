class SeatManager {

int prev;
priority_queue<int, vector<int>, greater<int>>  D;

public:
    // SeatManager(int n) {}
    SeatManager(int n) : prev(0) {}
    
    int reserve()
    {
        if (D.empty())
            return ++prev;
        int top = D.top();
        D.pop();
        return top;
    }
    
    void unreserve(int seatNumber) {
        if (seatNumber == prev)
            prev--;
        else
            D.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
