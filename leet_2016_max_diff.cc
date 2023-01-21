class Solution {
public:
    int maximumDifference(vector<int>& nums)
    {
        int     mini = (int) 1e9;
        int     res = -1;

        for (int & n: nums)
        {
            mini = min(mini, n);
            if (mini < n)
                res = max(res, n - mini);
        }
        return res; 
    }
};
