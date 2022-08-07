class Solution:
    def arraySign(self, nums: List[int]) -> int:
        if 0 in nums:
            return 0
        s = 1
        for i in nums:
            if i < 0:
                s=-s
        return -1 if s < 0 else 1
