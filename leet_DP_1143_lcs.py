class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        return [
            self.Solution_DP_bottom_up,
            self.Solution_DP_Topdown_No_LRU_cache,
            # self.Solution_DP_Topdown_start,
            # self.Solution_DP_Topdown_end
        ][ random.randint(0,0) ]( text1, text2 )

    def Solution_DP_bottom_up(self, text1, text2):
        print('/Solution_DP_bottom_up')
        R, C = len(text1), len(text2)
        dp = [ [0 for c in range(C + 1)] for r in range(R + 1) ]
        for r in range(1, R + 1):
            for c in range(1, C + 1):
                if text1[r - 1] == text2[c - 1]:
                    dp[r][c] = dp[r - 1][c - 1] + 1
                else:
                    dp[r][c] = max(dp[r - 1][c], dp[r][c - 1])
        return dp[R][C]

    def Solution_DP_Topdown_No_LRU_cache(self, text1, text2):
        print('/Solution_DP_Topdown_NoLRUcache - learned this from Larry')
        len1, len2 = len(text1), len(text2)
        has_cache = [[False] * len2 for _ in range(len1)]
        cache = [[None] * len2 for _ in range(len1)]
        def DP(r, c):
            if r == len1 or c == len2:
                return 0
            # Use home-made cache
            if has_cache[r][c]:
                return cache[r][c]

            if text1[r] == text2[c]:
                return DP (r + 1, c + 1) + 1
            res = max( DP(r + 1, c), DP(r, c + 1) )
            # Update cache
            has_cache[r][c] = True
            cache[r][c] = res

            return res #max( DP(r + 1, c), DP(r, c + 1) )
        return DP(0, 0)

    def Solution_DP_Topdown(self, text1, text2):
        print('/Solution_DP_Topdown')
        @lru_cache(maxsize=None)
        def DP(r, c):
            if r == len(text1) or c == len(text2):
                return 0
            if text1[r] == text2[c]:
                return DP (r + 1, c + 1) + 1
            return max( DP(r + 1, c), DP(r, c + 1) )
        return DP(0, 0)

    def Solution_DP_Topdown_start(self, text1, text2):
        print('/Solution_DP_Topdown_start')
        @lru_cache(maxsize=None)
        def DP(r, c):
            if r == len(text1) or c == len(text2):
                return 0
            if text1[r] == text2[c]:
                return DP (r + 1, c + 1) + 1
            return max( DP(r + 1, c), DP(r, c + 1) )
        return DP(0, 0)

    def Solution_DP_Topdown_end(self, text1, text2):
        print('/Solution_DP_Topdown_end')
        @lru_cache(maxsize=None)
        def DP(text1, r, text2, c):
            if r < 0 or c < 0:
                return 0
            if text1[r] == text2[c]:
                return DP (text1, r - 1, text2, c - 1) + 1
            return max( DP(text1, r - 1, text2, c), DP(text1, r, text2, c - 1) )
        return DP(text1, len(text1) - 1, text2, len(text2) - 1)

