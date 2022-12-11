class Solution {
public:
    int sumSubarrayMins(vector<int>& n) 
    {
        // vector<long long>   D; // deque and vector can interchange
        deque<long long>    D;
        vector<long long>   sums(n.size(), 0);

        int         i;
        long long   j;
        long long   tmp;
        long long   res = 0;
        long long   mod = 1e9 + 7;

        i = -1;
        while (++i < n.size())
        {
            while (!D.empty() && n[D.back()] > n[i])
                D.pop_back();

            //  original

            // if (D.empty())
            //     j = -1;
            // else
            //     j = D.back();
            // if (j == -1)
            //     tmp = 0;
            // else
            //     tmp = sums[j];

            //  ternary

            j = D.empty() ? -1 : D.back();
            tmp = j == -1 ? 0 : sums[j];
            sums[i] = (i - j) * n[i] + tmp;
            sums[i] %= mod;
            D.push_back(i);
        }
        i = -1;
        while (++i < sums.size())
        {
            res += sums[i];
            res %= mod;
        }
        return res;
    }
};
