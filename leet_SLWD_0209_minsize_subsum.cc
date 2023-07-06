// new

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int len = (int) nums.size();
        int L = 0, R = -1;
        int res = 2147483647;
        int temp = 0; // running sum
        int found = false;
        while (++R < len)
        {
            temp += nums[R];
            if (temp >= target)
                found = true;
            while (temp >= target)
            {
                res = min(R - L + 1, res);
                temp -= nums[L];
                ++L;
            }
        }
        return found ? res : 0;
    }
};

/*
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
*/
