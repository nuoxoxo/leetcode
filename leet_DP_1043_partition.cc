class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int N = (int) arr.size();
        vector<int> dp( N );
        int bigger = arr[0];
        int i = -2;
        while (++i + 1 < k)
        {
            if (bigger < arr[i + 1])
                bigger = arr[i + 1];
            dp[i + 1] = bigger * (i + 2);
        }
        while (++i < N)
        {
            bigger = arr[i];
            dp[i] = bigger + dp[i - 1];
            int j = i;
            while (--j > i - k)
            {
                if (bigger < arr[j])
                    bigger = arr[j];
                int temp = bigger * (i - j + 1) + dp[j -1];
                if (dp[i] < temp)
                    dp[i] = temp;
            }
        }
        return dp[N - 1];
    }
};
