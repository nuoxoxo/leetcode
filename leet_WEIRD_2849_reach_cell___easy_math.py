class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        if sx == fx and sy == fy:
            # return t % 2 != 1
            return t != 1
        dx = abs(sx - fx)
        dy = abs(sy - fy)
        if dx > t or dy > t:
            return False
        return True
