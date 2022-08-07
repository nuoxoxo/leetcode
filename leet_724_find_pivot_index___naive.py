class Solution:
    def pivotIndex(self, n: List[int]) -> int:
        cur, s = 0, sum(n)
        for i in range(len(n)):
            if i > 0:
                cur += n[i - 1]
            if cur == (s - n[i]) / 2:
                return i
        return -1
