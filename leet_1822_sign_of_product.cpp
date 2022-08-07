class Solution {
public:
    int arraySign(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int sign = 0;
        for (int n: nums)
        {
            if (n < 0)
                ++sign;
            if (n > 0)
                break ;
            if (!n)
                return 0 ;
        }
        return (sign % 2 ? -1 : 1);
    }
};
