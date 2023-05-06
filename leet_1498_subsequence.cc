class Solution {
public:
    int numSubseq(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());

        vector<int>     a{1};

        int i = 0;
        int mod = 1e9 + 7;
        while (++i < nums.size())
            a.push_back(a[i - 1] * 2 % mod);

        int l = 0, r = nums.size() - 1;
        int res = 0;
        while (l <= r)
        {
            if (nums[l] + nums[r] <= target)
            {
                res = (res + a[r - l]) % mod;
                ++l;
            }
            else
            {
                --r;
            }
        }
        return res % mod;
    }
};
