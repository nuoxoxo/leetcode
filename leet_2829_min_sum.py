class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        res = 0
        D = {}
        for i in range(1, 10 ** 9):
            if len(D) == n:
                break
            if k - i not in D:
                res += i
                D[i] = 1
        return res
