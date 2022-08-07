class Solution:
    def minimumTotal(self, tg: List[List[int]]) -> int:
        # n = len(tg)
        # if (n == 1):
        #     return tg[0][0]
        # if (n == 2):
        #     return tg[0][0] + min(tg[1])

        for i in range(len(tg) - 2, -1, -1):
            for j in range(len(tg[i])):
                tg[i][j] += min(tg[i + 1][j], tg[i + 1][j + 1])
        return tg[0][0]
