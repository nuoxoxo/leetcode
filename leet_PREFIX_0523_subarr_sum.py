class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:

        # insight : IIF a multiple of k is added to prev sum,
        # that we seen prev mod again

        seen = set()
        running = 0
        prev_mod = 0
        for n in nums:
            running += n
            curr_mod = running % k
            # print((running, running%k, seen) if seen else'empty')
            if curr_mod in seen:
                return True
            seen.add(prev_mod) # <--- delay adding so that sub len > 1 
            prev_mod = curr_mod
        return False
