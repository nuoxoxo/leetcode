class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        r = []
        for i in range(n):
            r += [nums[i], nums[i + n]]
        return r
