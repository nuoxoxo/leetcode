class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        # j - i != nums[j] - nums[i] --->
        # j-nums[j] ^ i-nums[i] = bad
        # j-nums[j] = i-nums[i] = good
        #   ---> a dict (not array) storing i-nums[i] is needed
        N = len(nums)
        pairs = N * (N - 1) // 2
        good = 0
        f = collections.defaultdict(int)
        for i in range(N):
            diff = i-nums[i]
            good += f[diff]
            f[diff] += 1
        return pairs - good        

