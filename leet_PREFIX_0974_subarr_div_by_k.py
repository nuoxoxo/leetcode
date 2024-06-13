class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        return [
            # Using_prefix_list,
            Running_prefix_sum,
        ][0](nums, k)

"""
a subarr can be expressed this way

-> a0 + a1 + a2 + ... + a[i - 1] + ai + ... + aj
->                                 ^^^^^^^^^^^^^ = f(j) - f(i - 1)

BECAUSE, in terms of line segment

-> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ = f(j)
-> ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ = f(i - 1)

a subarr sums 'divisible by k' IF :

-> (f(j) - f(i - 1)) === 0
-> f(j) % k === f(i - 1) % k ... this is what we want
-> so, keeping track of DICT[f(j) - k] == counting how many such subarrays
"""

def Running_prefix_sum(nums: List[int], k: int) -> int:
    res = 0
    running = 0
    prefix = defaultdict(int)
    prefix[0] = 1
    for n in nums:
        running += n
        running %= k
        res += prefix[running]
        prefix[running] += 1
    return res


