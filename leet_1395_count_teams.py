class Solution:
    def numTeams(self, rating: List[int]) -> int:
        return Reduction(rating)

def Reduction(rating: List[int]) -> int:
    from sortedcontainers import SortedList
    N = len(rating)

    def shrink(rating: List[int]) -> List[int]:
        res = []
        vis = SortedList()
        for r in rating:
            res.append( vis.bisect_left( r ) )
            vis.add(r)
        return res

    L = shrink(rating)
    R = shrink(rating[::-1])[::-1]

    def counter(l, r) -> int:
        res = 0
        for i in range(N):
            countleft = l[i]
            countright = (N - i - 1) - r[i]
            res += countleft * countright
        return res
    resL = counter(L, R)
    resR = counter(R[::-1], L[::-1])
    return resL + resR

def TLE(rating: List[int]) -> int:
    res = 0
    N = len(rating)
    for i in range(N):
        for j in range(i + 1, N):
            for k in range(j + 1, N):
                I, J, K = rating[i], rating[j], rating[k]
                if I < J < K:
                    res += 1
                elif I > J > K:
                    res += 1
    return res
