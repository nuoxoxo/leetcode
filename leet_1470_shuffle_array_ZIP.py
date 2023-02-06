class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        r = []
        a = nums[:n]
        b = nums[n:]
        for x, y in zip(a, b):
            r += [x, y]
        return r
