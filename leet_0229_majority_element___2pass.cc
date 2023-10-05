class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> res;
        int l, r, lc = 0, rc = 0;
        for (int n: nums)
        {
            if (l == n)
                lc++;
            else if (r == n)
                rc++;
            else if (!lc)
                lc = 1, l = n;
            else if (!rc)
                rc = 1, r = n;
            else
                --rc, --lc;
        }
        lc = 0, rc = 0;
        for (int n: nums)
        {
            if (n == l)
                lc++;
            else if (n == r)
                rc++;
        }
        if (lc > (int) nums.size() / 3)
            res.push_back(l);
        if (rc > (int) nums.size() / 3)
            res.push_back(r);
        return res;
    }
};
