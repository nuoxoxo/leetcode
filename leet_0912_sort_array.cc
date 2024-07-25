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
        // merge sort
        //  [5,2,3,1]
        //  [5,2]   [3,1]
        //  [5] [2] [3] [1] <--- single elements/ end of Dividing
        //  [5] [2] [3] [1] <--- sorting happens/ while Merging
        //       ^
        //               ^  <--- [2,5][1,3]
        //  [2,5]   [1,3]   <--- sorting/merging cont.
        //           ^      <--- [1]
        //   ^              <--- [1,2]
        //             ^    <--- [1,2,3]
        //  [1,2,3,5]

        function<vector<int>(int, int)> mergesort = [&](int L, int R)
        {
            
            if (L > R)
                return vector<int>{};
            int mid = nums[L];
            if (L == R)
                return vector<int>{mid};
            int M = (R - L) / 2 + L;
            vector<int> Lnums = mergesort(L, M);
            vector<int> Rnums = mergesort(M + 1, R);
            int l = 0;
            int r = 0;
            int NL = Lnums.size();
            int NR = Rnums.size();
            vector<int> res(NL + NR, 0);
            int curr = 0;
            while (l < NL && r < NR)
                Lnums[l] < Rnums[r] ? res[curr++] = Lnums[l++] : res[curr++] = Rnums[r++];
            while (l < NL)
                res[curr++] = Lnums[l++];
            while (r < NR)
                res[curr++] = Rnums[r++];
            return res;
        };

        return mergesort(0, nums.size() - 1);
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
