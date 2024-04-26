class Solution:
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        """
        15 - 157,159
        16 - 167,168
        24 - 248,249
        26 - 267,268
        34 - 348,349
        35 - 357,359
        """
        return [
            self.min_and_2nd_min_tracker,
            # self.nCubed,
        ][0](grid)

    def min_and_2nd_min_tracker(self, grid: List[List[int]]) -> int:

        INF = 10 ** 20
        N = len(grid)
        R, C = N, N
        dp = [[INF for _ in range(C)] for _ in range(R)]
        for c in range(C):
            dp[0][c] = grid[0][c]
        for r in range(1, R):
            # keep track of min and 2nd min values in the PREV row
            min_val, second_min_val = INF, INF
            min_idx, second_min_idx = -1, -1
            for c in range(C):
                if dp[r - 1][c] < min_val:
                    # branched out (1) - upd. min val if a smaller one is found
                    second_min_idx = min_idx
                    second_min_val = min_val
                    min_val = dp[r - 1][c]
                    min_idx = c
                elif dp[r - 1][c] < second_min_val:
                    # branched out (2) - when `min_val < PreviousRow[c] < second_min_val`
                    second_min_idx = c
                    second_min_val = dp[r - 1][c]
            # now upd. the current row while minding the adj. index
            for c in range(C):
                if c != min_idx:
                    dp[r][c] = grid[r][c] + min_val
                else:
                    dp[r][c] = grid[r][c] + second_min_val
        return min(dp[-1])


    def nCubed(self, grid: List[List[int]]) -> int:

        # Slow: O(n^3)
        INF = 10 ** 20
        N = len(grid)
        R, C = N, N
        dp = [[INF for _ in range(C)] for _ in range(R)]
        for c in range(C):
            dp[0][c] = grid[0][c]
        for r in range(1, R):
            for c in range(C):
                for idx in range(C):
                    if idx == c:
                        continue
                    temp = dp[r - 1][idx] + grid[r][c]
                    dp[r][c] = min(dp[r][c], temp)
        return min(dp[-1])

