class Solution:
    def judgeCircle(self, moves: str) -> bool:
        h, v = 0, 0
        for c in moves:
            if c == 'R':
                h += 1
            if c == 'L':
                h -= 1
            if c == 'U':
                v += 1
            if c == 'D':
                v -=1
        return v == 0 and h == 0
