class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        bool    isFound, tooLong;
        int     tmp, res, d, n, i, j;

        isFound = false;
        n = nums.size();
        res = 1e6;
        i = -1;
        if (find(nums.begin(), nums.end(), target) != nums.end())
            return 1;
        while (++i < n)
        {
            j = i;
            tmp = nums[i];
            tooLong = false;
            while (++j < n && tmp < target)
            {
                if (j - i >= res)
                {
                    tooLong = true;
                    break;
                }
                tmp += nums[j];
            }
            if (!tooLong && tmp >= target && j - i < res)
            {
                res = j - i;
                isFound = true;
            }
        }
        if (!isFound)
            return 0 ;
        return res ;
    }
};
