class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        h = sorted(heights)
        res = 0
        for i in range(len(h)):
            if h[i] != heights[i]:
                res += 1
        return res
