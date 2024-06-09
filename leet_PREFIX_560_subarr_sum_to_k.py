class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        """
        a subarr can be expressed this way
        -> a0 + a1 + a2 + ... + a[i - 1] + ai + ... + aj
        ->                                 ^^^^^^^^^^^^^ = f(j) - f(i - 1)
        BECAUSE, in terms of line segment
        -> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ = f(j)
        -> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ = f(i - 1)

        SO a subarr sums to k IF :
        -> f(j) - f(i - 1) === k, ... from which we can have
        -> f(j) - k === f(i - 1) ... this is what we want
        -> so, keeping track of DICT[f(j) - k] == counting how many such subarrays
        """

        res = 0
        prefix = defaultdict(int)
        prefix[0] = 1
        running = 0 # running prefix sum
        for n in nums:
            running += n
            j = running - k
            res += prefix[j]
            prefix[running] += 1
        return res

            

