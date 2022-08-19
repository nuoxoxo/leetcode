class Solution:
    def arithmeticTriplets(self, nums: List[int], diff: int) -> int:
        r = 0
        for n in nums:
            if (n + diff) in nums and (n + 2 * diff) in nums:
                r += 1
        return r
