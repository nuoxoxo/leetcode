class Solution:
    def checkRecord(self, n: int) -> int:
        MOD = 10 ** 9 + 7

        days, A, L = 0, 0, 0
        cache = [[ [0] * 3 for _ in range(2) ] for _ in range(n)]
        has_cache = [[[False] * 3 for _ in range(2)] for _ in range(n)]

        def DFS(days, A, L):
            # base and caching
            if days == n:
                return 1
            if has_cache[days][A][L]:
                return cache[days][A][L]
            res = 0
            # present - nothing happens
            res += DFS(days + 1, A, 0)
            # absent - add to A where max(A) == 1
            if A == 0:
                res += DFS(days + 1, A + 1, 0)
            # late - add to consecutive L where max(L) == 2
            if L < 2:
                res += DFS(days + 1, A, L + 1)
            res %= MOD
            cache[days][A][L] = res
            has_cache[days][A][L] = True
            return res
        return DFS(days, A, L)


