class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I /* intervals */)
    {
        sort(I.begin(), I.end(), [](vector<int> & a, vector<int> & b) {
            return a[0] < b[0];
        });
        int left = -2147483648;
        int res = 0;
        for (vector<int> & i: I)
        {
            if (left > i[0])
            {
                left = min(left, i[1]);
                res++;
            }
            else
                left = i[1];
        }
        return res;
    }
};
