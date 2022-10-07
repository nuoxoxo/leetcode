class MyCalendarThree {

private:
    map<int, int>   mp;

public:
    MyCalendarThree() {}

    int book(int start, int end)
    {
        int cur, res;

        res = 0;
        cur = 0;
        mp[start]++;
        mp[end]--;
        for (std::pair<int, int> x : mp) // this line can be re-written as:
        // for (auto & x : mp)
        {
            cur += x.second;
            res = max(cur, res);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
