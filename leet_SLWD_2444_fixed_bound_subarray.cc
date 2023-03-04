class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        int foundL = 0, foundR = 0;
        int L = 0, R = 0, i = -1;
        int start = 0;
        long long res = 0;

        while (++i < nums.size())
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                foundL = 0;
                foundR = 0;
                start = i + 1;
            }
            if (nums[i] == minK)
            {
                foundL = 1;
                L = i;
            }
            if (nums[i] == maxK)
            {
                foundR = 1;
                R = i;
            }
            if (foundL && foundR)
                res += min(L, R) - start + 1;
        }
        return res;
    }
};
