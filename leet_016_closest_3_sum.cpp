class Solution
{
    public:

        int threeSumClosest(vector<int>& nums, int target)
        {
            int     res, min, n, i, j, k, d;
            long    s;
            
            sort(nums.begin(), nums.end());
            s = nums[0] + nums[1] + nums[nums.size() - 1];
            min = abs(s - target);
            if (!min)   return (s);
            n = nums.size();
            i = -1;
            while (++i < n - 2)
            {
                if (!i || nums[i] != nums[i - 1])
                {
                    j = i + 1;
                    k = n - 1;
                    while (j < k)
                    {
                        s = nums[i] + nums[j] + nums[k];
                        d = abs(s - target);
                        if (!d) return (s);
                        if (min > d)
                        {
                            min = d;
                            res = s;
                        }
                        if (s > target) k--;
                        else            j++;
                    }
                }
            }
            return (res);
        }
};
