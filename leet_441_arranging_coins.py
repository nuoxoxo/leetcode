class Solution:
    def arrangeCoins(self, n: int) -> int:
        i = 0
        while True:
            i += 1
            if n < i + 1:
                break
            n -= i
        if i == n:
            return i
        return i - 1
