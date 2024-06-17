class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        return [
            # Initial_soln,
            # Binary_search,
        ][0](c)

def Initial_soln(c : int) -> bool:
    # two pointers
    l, r = 0, int(c ** .5)
    while l <= r:
        L = l * l
        R = r * r
        res = L + R
        if res == c: return True
        elif res < c:
            l += 1
        else:
            r -= 1
    return False
"""
5
3
8
9
10000000
"""
