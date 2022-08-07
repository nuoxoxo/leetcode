class MyCalendar {
public:

    vector<pair<int, int>>      mp;

    MyCalendar() { }
    
    bool book(int start, int end)
    {
        if (!is_npos(start, end, mp))
            return false;
        mp.push_back({start, end});
        return true;
    }

    bool    is_npos(int start, int end, vector<pair<int, int>> mp)
    {
        int                 L, R, mid, len;
        pair<int, int>      p;

        len = (int) mp.size();
        if (!len)
            return true;
        sort(mp.begin(), mp.end());
        L = 0;
        R = len - 1;
        while (L <= R)
        {
            mid = (R - L) / 2 + L;
            p = mp[mid];
            if (p.first <= start && p.second > start)
                return false;
            if (p.first < end && p.second >= end)
                return false;
            if (p.second <= start)
                L = mid + 1;
            else if (p.second >= end)
                R = mid - 1;
            else
                return false;
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
