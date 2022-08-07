class Solution:
    def rotateString(self, s: str, g: str) -> bool:
        if (s == g):
            return True
        lens = len(s)
        if lens is not len(g) or lens is 1:
            return False
        while len is not 0:
            g += g[0]
            g = g[1:]
            if (s == g):
                return True
        return False
