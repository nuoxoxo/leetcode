class Solution {
public:

    /*

    a subarr can be expressed this way
    -> a0 + a1 + a2 + ... + a[i - 1] + ai + ... + aj
    ->                                 ^^^^^^^^^^^^^ = f(j) - f(i - 1)

    SO a subarr sums to k IF :
    -> f(j) - f(i - 1) === k, ... from which we can have
    -> f(j) - k === f(i - 1) ... this is what we want
    -> so, keeping track of DICT[f(j) - k] == counting how many such subarrays

    */

    int subarraySum(vector<int>& nums, int k)
    {
        int res = 0;
        int running = 0;
        map<int, int> Prefix;

        Prefix[0] = 1;
        for (int n : nums)
        {
            running += n;
            res += Prefix[running - k];
            Prefix[running] += 1;
        }
        return res;
    }
};
