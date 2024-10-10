class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        Q = collections.deque()
        # idea/ - we need a monotonic decreasing stack
        for i, n in enumerate(nums):
            if not Q or n < nums[Q[0]]:
                Q.appendleft(i)
        res = 0
        for i in range(len(nums) - 1, -1, -1):
            while Q and nums[Q[0]] <= nums[i]:
                res = max(res, i - Q[0])
                Q.popleft()
        return res
