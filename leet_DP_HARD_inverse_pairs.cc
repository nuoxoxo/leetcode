class Solution {
public:
    int kInversePairs(int n, int k) {
       // sliding window soln by Neet
       vector<long long> dp(k + 1, 0);
       long long MOD = 1e9+7;
       dp[0] = 1;
       int i = 0;
       while (++i < n + 1)
       {
           vector<long long> cp(k + 1, 0);
           long long temp = 0;
           int kk = -1;
           while (++kk < k + 1)
           {
               if (kk > i - 1)
                   temp = (temp - dp[kk - i] + MOD) % MOD;
               temp = (temp + dp[kk]) % MOD;
               cp[kk] = temp;
           }
           dp = cp;
       }
       return (int) dp[k];
    }
};
