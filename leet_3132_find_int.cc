class Solution {
public:
    #define vi vector<int>
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2)
    {
        std::function<int(vi&, vi&)> ok;
        ok = [&](vi & L, vi & R) {
            int diff = L[0] - R[0];
            int N = L.size();
            assert(N == R.size());
            int i = -1;
            while (++i < N)
                if (L[i] - R[i] != diff)
                    return false;
            return true;
        };

        std::function<vi(vi&, int, int)> pop2elems = [&](vi & A, int l, int r) {
            auto ll = A.begin() + l;
            auto rr = A.begin() + r;
            vi res (A.begin(), ll);
            res.insert(res.end(), ll + 1, rr);
            res.insert(res.end(), rr + 1, A.end());
            return res;
        };

        // ACTION

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int N = nums1.size();
        int l = -1;
        int res = 2147483647;
        int stop = 0;
        while (++l < N - 1) {
            if (stop)
                break ;
            int r = l;
            while (++r < N) {
                // PYTHON -***-> alt = nums1[:i] + nums1[i + 1 : j] + nums1[j + 1:]
                vi alt = pop2elems(nums1, l, r);
                // vi alt (nums1.begin(), nums1.begin() + l); // the Left half
                // alt.insert(alt.end(), nums1.begin() + l + 1, nums1.begin() + r);
                // alt.insert(alt.end(), nums1.begin() + r + 1, nums1.end());
                if (ok(alt, nums2))
                {
                    res = nums2[0] - alt[0];
                    stop = 1;
                    break ;
                }
            }
        }
        return res;
    }
};

/*
- Statement
nums1 = [4,20,16,12,8]
nums2 = [14,18,10]
    - take out nums1[0] - 4
    - take out nums1[4] - 8
nums1 = [4,16,12]

- Sort both lists 
nums1 = [12,16,20]
nums2 = [10,14,18]

- Apply -2 to nums1
nums1 = [10,14,28]
nums1 == nums2
*/
