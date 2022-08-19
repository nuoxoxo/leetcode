class Solution:
    def maxDepth(self, s: str) -> int:
        r, t = 0, 0
        for c in s:
            if c is '(':
                t += 1
            if c is ')':
                t -= 1
            if t > r:
                r = t
        return r
