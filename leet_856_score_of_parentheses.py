class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        from collections import deque
        d = deque()
        p = 0 # points
        for c in s:
            if c is '(':
                d.append(p)
                p = 0
            else:
                p += d.pop() + max(p, 1)
        return p
