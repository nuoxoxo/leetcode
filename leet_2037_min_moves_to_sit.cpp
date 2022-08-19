class Solution {
public:
    int minMovesToSeat(vector<int>& sea, vector<int>& stu)
    {
        int r = 0, i;
        
        sort(sea.begin(), sea.end());
        sort(stu.begin(), stu.end());
        i = -1;
        while (++i < sea.size())
            r += abs(sea[i] - stu[i]);
        return r;
    }
};
