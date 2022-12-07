class Solution {
public:
    #define ll long long
    int minimumAverageDifference(vector<int>& nums)
    {
        int     len = (int) nums.size();
        ll      sum, l, r, i, min, res;
        ll      denom, diff;
        
        if (len == 1)
            return (0);
        sum = 0;
        for (ll n: nums)
        {
            sum += n;
        }
        min = (int) 1e9;
        res = -1;
        r = sum;
        l = 0;
        i = -1;
        while (++i < len)
        {
            l += nums[i];
            r -= nums[i];
            denom = len - i - 1;
            if (!denom)
                denom = 1;
            diff = abs(l / (i + 1) - (r / denom));
            if (min > diff)
            {
                min = diff;
                res = i;
            }
        }
        return (res);
    }
};
