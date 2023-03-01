class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int L = 0, R = nums.size() - 1;
        while (L < R)
        {
            int m = (R - L) / 2 + L;
            if (m % 2)
                --m;
            if (nums[m] == nums[m + 1])
                L = m + 2;
            else
                R = m;
        }
        return nums[L];
    }
};
