class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums)
    {
        vector<int>     res;
        int             len = (int) nums.size();
        int             i;
        int             made;
        int             left;

        if (len < 2)
        {
            res = {0, 1};
            return res;
        }
        sort(nums.begin(), nums.end());
        i = made = left = 0;
        while (i < len)
        {
            if (i + 1 < len)
            {
                if (nums[i] == nums[i + 1])
                {
                    made++;
                    i += 2;
                }
                else
                {
                    left++;
                    i += 1;
                }
            }
            else
            {
                left++;
                i += 1;
            }
        }
        res = {made, left};
        return (res);
    }
};
