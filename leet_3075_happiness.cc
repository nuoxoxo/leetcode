class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {

        vector<long long(*)(vector<int>&, int)> Solutions {
            // Nopopping,
            Binary_search_precalc,
        };
        return Solutions[0](happiness, k);
    }

    static long long Binary_search_precalc(vector<int>& happiness, int k)
    {

        sort(begin(happiness), end(happiness), std::greater<>());
        if (happiness[k - 1] - (k - 1) > -1)
        {
            long long sumK = 0;
            long long i = -1;
            while (++i < k)
                sumK += happiness[i];
            long long diff = 0;
            while (--k)
                sumK -= k;
            return sumK;
        }
        long long res = 0;
        long long i = -1;
        while (++i < happiness.size())
        {
            long long temp = happiness[i] - i;
            if (temp < 1)
                return res;
            res += temp;
        }
        return res;
    }

    static long long Nopopping(vector<int>& happiness, int k)
    {

        sort(begin(happiness), end(happiness), std::greater<>());
        long long res = 0;
        long long i = 0;
        while (k)
        {
            long long temp = happiness[i] - i;
            if (temp < 1)
                return res;
            res += temp;
            i++;
            k--;
        }
        return res;
    }
};
