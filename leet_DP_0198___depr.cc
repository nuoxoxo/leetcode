class Solution {
public:
	int rob(vector<int>& nums)
	{
		int	n = nums.size();

		if (n == 1)
			return (nums[0]);
		if (n == 2)
			return (max(nums[0], nums[1]));
		if (n == 3)
			return (max(nums[0] + nums[2], nums[1]));

		vector<int>	D(n);
		int		i = 2;

		D[0] = nums[0];
		D[1] = nums[1];
		D[2] = max(nums[0] + nums[2], nums[1]);
		while (++i < n)
			D[i] = max(nums[i] + D[i - 2], nums[i] + D[i - 3]);
		return (max(D[i - 1], D[i - 2])) ;
	}
};
