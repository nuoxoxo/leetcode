class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        for i in range(n):
            tmp = start + 2 * i
            if i != 0:
                res ^= tmp
            else:
                res = tmp
        return res
