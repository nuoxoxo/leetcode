class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        bool    isFound = false;
        int     n = nums.size();
        int     res = 1e6;
        int     sum = 0;
        int     fast = -1;
        int     slow = 0;
        while (++fast < n)
        {
            sum += nums[ fast ];
            while (sum >= target)
            {
                isFound = true;
                res = min(res, fast - slow + 1);
                sum -= nums[slow];
                ++slow;
            }
        }
        if (isFound)
            return res;
        return 0;
    }
};
