class Solution {
public:
    #define vi vector<int>
    int lengthOfLIS(vector<int>& nums) {
        vector<int(*)(vi&)> Solutions {
            // Binary_search, // fast
            // Lower_bound, // fast
            nSquare,
        };
        return Solutions[0](nums);
    }

    static int Lower_bound(vi& nums)
    {
        vi lens;
        for (int n: nums)
        {
            auto it = std::lower_bound(lens.begin(), lens.end(), n);
            if (it == lens.end())
                lens.push_back(n);
            else
                *it = n;
        }
        return (int)lens.size();
    }

    static int Binary_search(vi& nums)
    {
        vi lens;
        for (int n: nums)
        {
            int N = lens.size();
            if (lens.empty() || lens[N - 1] < n)
            {
                lens.push_back(n);
            }
            else
            {
                int L = 0;
                int R = N - 1;
                while (L < R)
                {
                    int mid = (R - L) / 2 + L;
                    if (lens[mid] < n)
                        L = mid + 1;
                    else
                        R = mid;
                }
                lens[R] = n;
            }
        }
        return (int)lens.size();
    }

    static int nSquare(vi& nums)
    {
        int N = nums.size();
        long long INF = 2147483648;
        vector<long long> lens(N + 1, INF);
        lens[0] = -INF;
        for (int n: nums)
        {
            int i = -1;
            while (++i < N + 1)
            {
                if (lens[i] < n)
                {
                    if (lens[i + 1] > n)
                        lens[i + 1] = n;
                }
            }
        }
        int res = -1;
        int i = N + 1;
        while (--i > -1)
        {
            if (lens[i] != INF)
            {
                res = i;
                break ;
            }
        }
        return res;
    }
};
