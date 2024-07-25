class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        vector<vector<int>(*)(vector<int>&)> Solutions = {
            // MergeSort_backinserter,
            MergeSort,
        };
        return Solutions[0](nums);
    }

    static vector<int> MergeSort(vector<int> & nums)
    {
        function<vector<int>(int, int)> mergesort = [&](int L, int R)
        {
            if (L > R)
                return vector<int>{};
            if (L == R)
                return vector<int>{ nums[L] };
            int M = (R - L) / 2 + L;
            vector<int> Lnums = mergesort(L, M);
            vector<int> Rnums = mergesort(M + 1, R);
            vector<int> res;
            int l = 0;
            int r = 0;
            int NL = Lnums.size();
            int NR = Rnums.size();
            while (l < NL && r < NR)
            {
                if (Lnums[l] < Rnums[r])
                {
                    res.push_back(Lnums[l]);
                    l++;
                }
                else
                {
                    res.push_back(Rnums[r]);
                    r++;
                }
            }
            while (l < NL)
            {
                res.push_back(Lnums[l++]);
                // l++;
            }
            while (r < NR)
            {
                res.push_back(Rnums[r++]);
            }
            return res;
        };
        int N = nums.size();
        return mergesort(0, N - 1);
    }

    static vector<int> MergeSort_backinserter(vector<int> & nums)
    {
        int mid = nums.size() / 2;
        vector<int> L(begin(nums), begin(nums) + mid);
        vector<int> R(begin(nums) + mid, end(nums));
        vector<int> res;
        sort(begin(L), end(L));
        sort(begin(R), end(R));
        merge(begin(L), end(L), begin(R), end(R), back_inserter<vector<int>> (res));
        return res;
    }
};
