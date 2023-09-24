class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        res = [[0 for _ in range(102)] for _ in range(102)]
        res[0][0] = poured
        for i in range(query_row + 1):
            for j in range(i + 1):
                if res[i][j] > 1:
                    tmp = res[i][j] - 1
                    res[i][j] = 1
                    res[i + 1][j] = res[i + 1][j] + tmp / 2
                    res[i + 1][j + 1] = res[i + 1][j + 1] + tmp / 2
        return res[query_row][query_glass]
