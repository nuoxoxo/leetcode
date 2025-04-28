class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        return [
            Greedy,
            TLE,
        ][0](days,meetings)

def Greedy(days,meetings) -> int:
    ok = 0
    R = 0 # current furthest end
    for l,r in sorted(meetings):
        l -= 1
        if R < l:
            ok += l - R
        R = max(R,r)
    return ok + days - R

def TLE(days,meetings) -> int:
    d = [1] * days
    for l,r in meetings:
        for i in range(l,r+1):
            d[i-1] = 0
    return sum(d)
