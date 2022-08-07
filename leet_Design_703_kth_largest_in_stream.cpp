class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
    {
        s = k;
        for (int n: nums)
            p.push(n);
        if (p.size() > k)
            p.pop();
    }
    
    int add(int val)
    {
        p.push(val);
        while (p.size() > s)
            p.pop();
        return p.top();
    }
    
    priority_queue<int, vector<int>, std::greater<int>>  p;
    int s;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
