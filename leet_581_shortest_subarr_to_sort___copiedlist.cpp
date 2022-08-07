class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> copy = nums;
        int         n = (int) nums.size();
        int         i = -1;
        int         mark = 0;

        sort(nums.begin(), nums.end());
        while (++i < n)
        {
            if (nums[i] ^ copy[i])
            {
                mark = i;
                break;
            }
        }
        i = n;
        while (--i > -1)
        {
            if (nums[i] ^ copy[i])
                return i + 1 - mark;
        }
        return mark;
    }
};

/*
[1,3,2,4,5]
[1,3,2,2,2]
*/
