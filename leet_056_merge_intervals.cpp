class Solution {
public:
    #define vi  vector<int>
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int         len = intervals.size() ;
        vector<vi>  res ;

        if (!len)
            return res ;
        if (len == 1)
            return intervals ;

        sort(intervals.begin(), intervals.end());

        vi  tmp = intervals[0];
        int i = 0;

        while (++i < len)
        {
            if (tmp[1] >= intervals[i][0])
                tmp[1] = max( tmp[1], intervals[i][1] );
            else
            {
                res.push_back(tmp);
                tmp = intervals[i];
            }
        }
        res.push_back(tmp) ;
        return res ;
    }
};
