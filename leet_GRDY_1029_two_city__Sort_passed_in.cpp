class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& c)
    {
        sort(c.begin(), c.end(), [](vector<int> a, vector<int> b) { return a[0] - a[1] < b[0] - b[1] ; });
        int half = c.size() / 2 ;
        int res = 0 ;
        int i = -1 ;
        while (++ i < half)
            res += c[i][0] + c[i + half][1] ;
        return res ;
    }
};
