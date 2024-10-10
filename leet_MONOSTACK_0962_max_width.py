class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        D = collections.deque()
        r = 0
        for i in range(len(nums)):
            if not D or nums[i] < nums[D[0]]:
                D.appendleft(i)
        for i in range(len(nums) - 1, -1, -1):
            while D and nums[i] >= nums[D[0]]:
                r = max(i - D.popleft(), r)
        return r
