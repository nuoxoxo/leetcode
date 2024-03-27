class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if (k < 2)
            return 0 ;

        int count, prod, i, j;

        count = 0;
        prod = 1;
        i = -1;
        j = 0;
        while (++i < nums.size())
        {
            prod *= nums[i];
            while (prod >= k)
            {
                prod /= nums[j];
                ++j;
            }
            count += i - j + 1;
        }
        return count ;
    }
};
