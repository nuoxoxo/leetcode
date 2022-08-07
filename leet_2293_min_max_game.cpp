class Solution {
public:
    int minMaxGame(vector<int>& nums)
    {
        vector<int>     temp;
        int             len, n, i;

        len = (int) nums.size();
        while (len > 1)
        {
            len /= 2;
            i = -1;
            while (++i < len)
            {
                if (i % 2)
                    n = max(nums[i * 2], nums[i * 2 + 1]);
                else
                    n = min(nums[i * 2], nums[i * 2 + 1]);
                temp.push_back(n);
            }
            nums = temp;
            temp.clear();
        }
        return (nums[0]);
    }
};
