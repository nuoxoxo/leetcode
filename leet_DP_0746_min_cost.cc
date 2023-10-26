class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int L, R, i, n;
        int size = cost.size();

        vector<int> dp(size + 1);
        dp[0] = 0;
        dp[1] = 0;
        i = 1;
        while (++i < size + 1)
        {
            L = dp[i - 2] + cost[i - 2];
            R = dp[i - 1] + cost[i - 1];
            dp[i] = L < R ? L : R;
        }
        return dp[size] ;
    }
};;
