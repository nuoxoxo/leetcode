class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        first = garbage[0]
        gg = first.count('G')
        mm = first.count('M')
        pp = first.count('P')
        G, M, P = gg, mm, pp
        for i in range(1, len(garbage)):
            t = travel[i - 1]
            s = garbage[i]
            ifg, ifm, ifp = s.count('G'), s.count('M'), s.count('P')
            gg += t + ifg
            mm += t + ifm
            pp += t + ifp
            if ifg > 0:
                G = gg
            if ifm > 0:
                M = mm
            if ifp > 0:
                P = pp
        return G + M + P
