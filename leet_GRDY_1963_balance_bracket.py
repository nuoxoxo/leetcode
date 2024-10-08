class Solution:
    def minSwaps(self, s: str) -> int:
        return [
            Greedy,
        ][0](s)

def Greedy(s: str) -> int:
    if not s: return 0
    blc, swp = 0, 0
    for c in s:
        if c == '[': blc += 1
        else: blc -= 1
        if blc == -1:
            blc = 1
            swp += 1
    return swp

