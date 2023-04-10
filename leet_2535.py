class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        r1 = sum(nums)
        r2 = sum([int(_) for _ in ''.join([str(n) for n in nums])])
        return int(r1 - r2)
