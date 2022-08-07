class Solution:
    def checkStraightLine(self, co: List[List[int]]) -> bool:
        n = len(co)
        if n == 2:
            return True
        dx = co[1][0] - co[0][0]
        dy = co[1][1] - co[0][1]
        slope = -1 if dx == 0 else dy / dx
        for i in range(2, n):
            dx = co[i][0] - co[i - 1][0]
            dy = co[i][1] - co[i - 1][1]
            temp_slope = -1 if dx == 0 else dy / dx
            if temp_slope != slope:
                return False
        return True
