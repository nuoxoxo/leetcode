class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        t = 0
        for c in stones:
            if c in jewels:
                t += 1
        return t
