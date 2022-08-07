class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int len = nums.size();
        int res = len;
        int i = -1;
        while (++i < len)
        {
            res ^= nums[i] ^ i;
        }
        return res;
    }
};
