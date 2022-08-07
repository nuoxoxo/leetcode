class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return (a[0] - a[1] < b[0] - b[1]) ;
    }

    int twoCitySchedCost(vector<vector<int>>& cost)
    {
        int i = -1, res = 0, n = cost.size() / 2;

        sort(cost.begin(), cost.end(), cmp) ;
        while (++ i < n)
            res += cost[i][0] + cost[i + n][1] ;
        return res ;
    }
};
