class Solution
{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        int                 i, j, x, y;
        long                t;
        vector<vector<int>> res;
        
        if (nums.size() < 4)    return (res);
        sort(nums.begin(), nums.end());
        i = -1;
        while (++i < nums.size() - 3)
        {
            j = nums.size();
            while (--j > i)
            {
                x = i + 1;
                y = j - 1;
                while (x < y)
                {
                    t = (long) nums[i] + (long) nums[j] + (long) nums[x] + (long) nums[y];
                    if (t == target)
                    {
                        vector<int> tmp{nums[i], nums[x], nums[y], nums[j]};
                        if (find(res.begin(), res.end(), tmp) == res.end())
                            res.push_back(tmp);
                        while (x < y && nums[x] == nums[x + 1]) x++;
                        while (x < y && nums[y] == nums[y - 1]) y--;
                        x += 1;
                        y -= 1;
                    }
                    else if ( t < target )  x++;
                    else                    y--;
                }
            }
        }
        return (res);
    }
};
