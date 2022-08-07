class Solution {
public:
    vector<int> runningSum(vector<int>& nums)
    {
        int n = (int) nums.size();
        int run = 0;
        int i = -1;
        vector<int> res(n, 0);

        while (++i < n)
        {
            run += nums[i];
            res[i] = run;
        }
        return res;
    }
};
