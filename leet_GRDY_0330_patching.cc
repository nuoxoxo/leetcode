class Solution {
public:
    int minPatches(vector<int>& nums, int n)
    {
        int res = 0;
        long long L = 0, R = 0;
        for (int num : nums)
        {
            while (R < n && num > R + 1) // gap exists [R + 1, n - 1]
            {
                R += R + 1;
                ++res;
            }
            R += num;
        }
        while (R < n)
        {
            R += R + 1;
            ++res;
        }
        return res;
    }
};
