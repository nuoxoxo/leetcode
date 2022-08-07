class Solution {
public:
    int maximumUnits(vector<vector<int>>& t, int truckSize)
    {
        sort(t.begin(), t.end(), &cmp);
        int len = (int) t.size();
        int res = 0, i, j;

        i = -1;
        while (++i < len)
        {
            vector<int> B = t[i];   // number of such boxes

            j = -1;
            while (++j < B[0])
            {
                if (truckSize < 1)
                    return res;
                res += B[1];
                truckSize --;
            }
        }
        /*
        i = -1;
        while (++i < len)   cout<<t[i][0]<<' '<<t[i][1]<<endl;
        */
        return res;
    }

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[1] > b[1])
            return true;
        if (a[1] == b[1])
            return a[0] > b[0];
        return false;
    }
};
