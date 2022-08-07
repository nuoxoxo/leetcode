class Solution:
    def countOdds(self, low: int, high: int) -> int:
        d = (high - low) // 2
        if low % 2 != 0 or high % 2 != 0:
            return d + 1
        return d
