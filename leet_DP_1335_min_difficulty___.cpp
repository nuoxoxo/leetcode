class Solution
{
	public:
	int minDifficulty(vector<int>& jobDifficulty, int D)
	{

		int                     maxi = INT_MIN;
		int                     n = jobDifficulty.size();
		vector<vector<int>>     dp(n + 1, vector<int>(D + 1, 0));

		if (n < D) //impossible case
			return -1;
		// storing base case
		// // if d == 1, max of partition elements will be answer
		// // here we store the max from back

		for (int i = n - 1; i >= 0; i--)
		{
			maxi = max(maxi, jobDifficulty[i]);
			dp[i][1] = maxi;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			for (int d = 2; d <= D; d++)
			{
				int     ans = INT_MAX;
				int     max_elem = 0;

				for (int j = i; j < n - d + 1; j++)
				{
					max_elem = max(max_elem, jobDifficulty[j]);
					//max element from i to j
					ans = min(ans, max_elem + dp[j+1][d-1]);
					//minimum of all possible answers
				}
				dp[i][d] = ans;
			}
		}
		return dp[0][D];
	}
};
