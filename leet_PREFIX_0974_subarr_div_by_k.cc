class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        /*

        a subarr can be expressed this way
        -> a0 + a1 + a2 + ... + a[i - 1] + ai + ... + aj
        ->                                 ^^^^^^^^^^^^^ = f(j) - f(i - 1)

        SO a subarr sums to k IF :
        -> f(j) - f(i - 1) === k, ... from which we can have
        -> f(j) - k === f(i - 1) ... this is what we want
        -> so, keeping track of DICT[f(j) - k] == counting how many such subarrays

        */

        int res = 0;
        int running = 0;
        map<int, int> prefix {{0, 1}};

        for (int n : nums)
        {
            running += n;
            running = (running % k + k) % k; // make sure the MOD is a positive (remainder)
            res += prefix[running];
            prefix[running]++;
        }
        return res;
    }
};
