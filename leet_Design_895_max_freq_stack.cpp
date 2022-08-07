class FreqStack {
public:

    map<int, vector<int>>   group ;
    map<int, int>           count ;
    int                     mx = 0;

    FreqStack() {}
    
    void push(int val)
    {
        count[val] ++ ;
        if (count[val] > mx)
            mx ++ ;
        group[count[val]].push_back(val);
    }
    
    int pop()
    {
        int res = group[mx].back();

        count[res] -- ;
        group[mx].pop_back();
        if (group[mx].empty())
            mx -- ;
        return res ;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
