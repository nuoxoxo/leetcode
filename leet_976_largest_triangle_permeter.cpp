class Solution {
public:
    int largestPerimeter(vector<int>& nums)
    {
        int		res;
	int		i;

	res = 0;
	i = -1;
        sort(nums.begin(), nums.end(), greater<int>());
        while (++i < nums.size() - 2)
        {
            if (nums[i] < nums[i + 1] + nums[i + 2])
            {
                res = nums[i] + nums[i + 1] + nums[i + 2];
                break;
            }
        }
        return res ;
    }
};
