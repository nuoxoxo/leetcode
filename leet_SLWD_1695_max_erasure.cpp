class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        int n = (int) nums.size();
        if (n == 1)
            return nums[0];
        set<int>    s;
        long        res, cur;
        int         L, R;
        cur = res = 0;
        L = R = 0;
        while (R < n)
        {
            if (s.find(nums[R]) != s.end())
            {
                res = max(res, cur);
                cur -= nums[L];
                s.erase(nums[L]);
                ++L;
            }
            else
            {
                cur += nums[R];
                s.insert(nums[R]);
                ++R;
            }
        }
        res = max(res, cur);
        return res;
    }
};
