class Solution:
    def nearestValidPoint(self, x: int, y: int, p: List[List[int]]) -> int:
        res = 1e9
        idx = 1e9
        for i in range(len(p)):
            if x == p[i][0]:
                dif = abs(p[i][1] - y)
                if dif < res:
                    res = dif
                    idx = i
            elif y == p[i][1]:
                dif = abs(p[i][0] - x)
                if dif < res:
                    res = dif
                    idx = i
            if res is 0:
                return i
        return -1 if idx == 1e9 else idx
