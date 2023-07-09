class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int i = 0;
        int res = 0;
        while (++i < (int) nums.size())
        {
            if (nums[i - 1] < nums[i])
                continue ;
            int dist = nums[i - 1] - nums[i] + 1;
            res += dist;
            nums[i] = nums[i - 1] + 1;
        }
        return res;
    }
};
