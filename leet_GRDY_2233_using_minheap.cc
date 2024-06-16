class Solution {
public:
    int maximumProduct(vector<int>& nums, int k)
    {
        /*
        2 * 2 * 4 = 16
                ^
        2 * 2 * 5 = 20
        or
        ^
        3 * 2 * 4 = 24 <--- always incr. the smallest val
        */
        int MOD = 1000000007;
        std::priority_queue<int, vector<int>, greater<int>> P;
        for (int n : nums)
            P.push(n);
        while (k)
        {
            int mini = P.top();
            mini += 1;
            mini %= MOD;
            --k;
            P.pop();
            P.push(mini);
        }
        long long res = 1;
        while (!P.empty())
        {
            int mini = P.top() % MOD;
            P.pop();
            res = (mini * (res % MOD)) % MOD;
        }
        return (int) res;
    }
};
