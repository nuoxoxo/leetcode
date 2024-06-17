class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        return [
            # Initial_soln,
            Using_set,
        ][0](c)

def Using_set(c : int) -> bool:
    seen = set()
    for n in range(0, c + 1):
        sq = n * n
        seen.add(sq) # 
        if sq > c:
            break
        if c - sq in seen:
            return True
    return False

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
2
8
9
10000000
"""
