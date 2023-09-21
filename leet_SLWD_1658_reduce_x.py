class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        size = len(nums)
        tt = sum(nums)
        L = 0
        curr = 0
        window = -1 # max window length, -1 if no window exists
        for R in range(size):
            curr += nums[R]
            while curr > tt - x and L <= R:
                curr -= nums[L]
                L += 1
            if curr == tt - x:
                window = max(window, R - L + 1)
        return size - window if window != -1 else -1

