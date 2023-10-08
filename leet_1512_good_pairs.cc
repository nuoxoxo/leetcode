class Solution {
public:
    int numIdenticalPairs(vector<int>& nums)
    {
        int res = 0, len = nums.size(), i = -1, j;

        while (++i < len)
        {
            j = i;
            while (++j < len)
            {
                if (nums[i] == nums[j])
                    res++;
            }
        }
        return res;
    }
};
