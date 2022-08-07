class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& itv)
    {
        int count, left, right, len, i;

        sort(itv.begin(), itv.end()) ;
        right = left = -1e9;
        len = itv.size();
        count = 0 ;
        i = -1;
        while (++i < len)
        {
            if (right < itv[i][1] && left < itv[i][0])
            {
                left = itv[i][0];
                count += 1;
            }
            right = right > itv[i][1] ? right : itv[i][1];
        }
        return count ;
    }
    
    
};
