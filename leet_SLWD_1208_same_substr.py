class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        return [
            Sliding_window,
        ][0](s, t, maxCost)

def Sliding_window(s: str, t: str, maxCost: int) -> int:
    N = len(t)
    L = 0
    windowcost = 0
    res = 0
    for R in range(N):
        diff = ord(s[R]) - ord(t[R])
        windowcost += abs(diff)
        while windowcost > maxCost:
            diff = ord(s[L]) - ord(t[L])
            windowcost -= abs(diff)
            L += 1
        res = max(res, R - L + 1)
    return res
