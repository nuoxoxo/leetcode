class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        return [
            # self.DP_iterative_tabulation,
            self.DP_recursive_cached_count,
        ][ 0 ]( m, n, maxMove, startRow, startColumn )

    def DP_recursive_cached_count(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        print('/DP_recursive_cached_count using DIY caching, learned from Larry')
        MOD = 10**9 + 7
        DR = [-1, 0,1,0]
        DC = [ 0,-1,0,1]
        has_cache = [[[False for _ in range(maxMove + 1)] for _ in range(n)] for _ in range(m)]
        cache = [[[None for _ in range(maxMove + 1)] for _ in range(n)] for _ in range(m)]
        # @lru_cache(None)
        def DP(r, c, moves):
            res = 0
            if not -1 < r < m or not -1 < c < n:
                return 1
            elif moves == maxMove:
                return 0
            if has_cache[r][c][moves]:
                return cache[r][c][moves]
            for dr, dc in zip(DR, DC):
                res += (DP(r + dr, c + dc, moves + 1))# % MOD
            res# %= MOD
            has_cache[r][c][moves] = True
            cache[r][c][moves] = res
            return res
        return DP(startRow, startColumn, 0) % MOD

    def DP_iterative_tabulation(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        print('/DP_iterative_tabulation')
        dp = [[0] * n for _ in range(m)]
        MOD = 10**9 + 7
        DR = [-1, 0,1,0]
        DC = [ 0,-1,0,1]
        cp = [_[:] for _ in dp]# copy.deepcopy(dp) # 2 ways
        for _ in range(maxMove):
            for r in range(m):
                for c in range(n):
                    temp = 0
                    for dr, dc in zip(DR, DC):
                        rr = r + dr
                        cc = c + dc
                        if not -1 < rr < m or not -1 < cc < n:
                            temp += 1
                            temp %= MOD
                        else:
                            temp += (dp[rr][cc] % MOD)
                    cp[r][c] = (temp % MOD)
            dp = [_[:] for _ in cp]#copy.deepcopy(cp)# copy.deepcopy(dp) # both ok
            for _ in cp:print(_)
            print()
        return dp[ startRow ][ startColumn ]
                    
