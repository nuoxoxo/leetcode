class Solution:
    def brokenCalc(self, start: int, target: int) -> int:
        if start >= target:
            return start - target
        if target % 2 == 0:
            return 1 + self.brokenCalc(start, target // 2)
        return 1 + self.brokenCalc(start, target + 1)
