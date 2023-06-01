class Solution {
public:
    #define vi  vector<int>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<vi>  res;
        vector<vi>  v;
        int         i;

        i = -1;
        while (++ i < points.size())
        {
            int	temp = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            v.push_back({temp, i});
        }
        sort(v.begin(), v.end());
        i = -1;
        while (++i < k)
            res.push_back(points[v[i][1]]);
        return res ;
    }
};
