class Solution:
    def hIndex(self, citations: List[int]) -> int:
        res = 0
        for i, n in enumerate(sorted(citations, reverse=True)):
            if n > i:
                res = i + 1
            else:
                break
        return res
