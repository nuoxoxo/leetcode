class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        res = 0
        R, C = len(matrix), len(matrix[0])
        SUMS = [[0] * C for _ in range(R + 1)]
        for r in range(1, R + 1):
            for c in range(C):
                ### cumulative sums for each col up to the current row
                SUMS[r][c] = SUMS[r - 1][c] + int (matrix[r - 1][c])

        """
        1 0 1 0 0
        1 0 1 1 1
        1 1 1 1 1
        1 0 0 1 0

        cumulative sums
        0 0 0 0 0
        1 0 1 0 0
        2 0 2 1 1
        3 1 3 2 2
        4 1 3 3 2
        """

        def allones(upper, lower, c):

            ### check if:
            ### within a column range from upper to lower are '1's
            ### ---> we have all '1's if the Sum == Number of rows in-btw

            slots = lower - upper + 1
            return slots == SUMS[lower + 1][c] - SUMS[upper][c]

            ### old way is TLE ---> must use DP

            """
            for r in range(upper, lower + 1):
                if matrix[r][c] == '0':
                    return False
            return True
            """
        for top in range(R):
            for btm in range(top, R):
                cols = 0
                for c in range(C):
                    if allones (top, btm, c):
                        cols += 1
                    else:
                        cols = 0
                    rows = btm - top + 1
                    res = max( rows * cols, res )
        return res


