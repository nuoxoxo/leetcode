class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        ss, tt = [], []
        for c in s:
            if c != '#':
                ss.append(c)
            elif ss:
                ss.pop()
        for c in t:
            if c != '#':
                tt.append(c)
            elif tt:
                tt.pop()
        return ss == tt
