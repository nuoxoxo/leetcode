class Solution {
public:
    int minIncrementForUnique(vector<int>& nums)
    {
        int res = 0;
        sort(begin(nums), end(nums));
        int N = nums.size();
        int i = -1;
        while (++i < N - 1)
        {
            if (nums[i] >= nums[i + 1])
            {
                int need = nums[i] - nums[i + 1] + 1;
                nums[i + 1] += need;
                res += need;
            }
        }
        return res;;
    }
};
