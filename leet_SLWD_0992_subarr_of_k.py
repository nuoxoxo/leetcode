class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:

        def subarr_with_no_more_than_k_distinct(nums, k) -> int:
            N = len(nums)
            D = defaultdict(int)
            l = 0
            res = 0
            for r, n in enumerate(nums):
                D[n] += 1
                while len(D) > k:
                    D[nums[l]] -= 1
                    if D[nums[l]] == 0:
                        del D[nums[l]]
                    l += 1
                res += r - l + 1
            return res

        return subarr_with_no_more_than_k_distinct(nums, k) - \
            subarr_with_no_more_than_k_distinct(nums, k - 1)
