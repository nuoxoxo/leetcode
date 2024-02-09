class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = (int) nums.size();
        if (!len)
            return {};
        vector<vector<int>> dp(len, vector<int>());
        sort(nums.begin(), nums.end());
        int i = -1;
        while (++i < len)
            dp[i].push_back(nums[i]);
        i = -1;
        while (++i < len)
        {
            int j = -1;
            while (++j < i)
            {
                if ( nums[i] % nums[j] == 0 && dp[i].size() - 1 < dp[j].size())
                {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
            }
        }
        i = -1;
        int max = -1e9, pos = -1;
        while (++i < len)
        {
            int N = dp[i].size();
            if (max < N)
            {
                pos = i;
                max = N;
            }
        }
        return dp[pos];
    }
};
