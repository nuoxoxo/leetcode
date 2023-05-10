class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0 for _ in range(n)] for _ in range(n)]
        lim = n * n + 1
        cnt = 1
        i, j, d = 0, 0, 0
        while True:
            while j < n - d:    # top
                res[i][j] = cnt
                cnt += 1
                j += 1
            if cnt == lim:
                break
            i += 1
            j -= 1
            while i < n - d:    # right
                res[i][j] = cnt
                cnt += 1
                i += 1
            if cnt == lim:
                break
            i -= 1
            j -= 1
            while j > d - 1:    # bottom
                res[i][j] = cnt
                cnt += 1
                j -= 1
            if cnt == lim:
                break
            i -= 1
            j += 1
            d += 1  # update bound at end of cycle
            while i > d - 1:
                res[i][j] = cnt
                cnt += 1
                i -= 1
            if cnt == lim:
                break
            i += 1
            j += 1
        return res
