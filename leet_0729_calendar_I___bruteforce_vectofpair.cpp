class MyCalendar {
public:

    vector<pair<int, int>>      mp;

    MyCalendar() { }
    
    bool book(int start, int end)
    {
        for (pair<int, int> p: mp)
        {
            if (!(p.second < start || p.first > end - 1))
                return false;
        }
        mp.push_back({start, end - 1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
