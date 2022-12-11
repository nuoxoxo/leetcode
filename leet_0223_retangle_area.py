class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        sa = abs(ax2 - ax1) * abs(ay2 - ay1)
        sb = abs(bx2 - bx1) * abs(by2 - by1)
        ss = sa + sb
        x = min(ax2, bx2) - max(ax1, bx1)
        y = min(ay2, by2) - max(ay1, by1)
        ov = 0 if x < 1 or y < 1 else x * y
        return ss - ov
