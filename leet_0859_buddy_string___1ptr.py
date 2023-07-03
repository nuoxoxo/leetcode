class Solution:
    def buddyStrings(self, s: str, g: str) -> bool:
        L = len(s)
        if L != len(g):
            return False
        if s == g and L ^ len(set(s)):
            return True
        D = []
        for i in range(L):
            if s[i] == g[i]:
                continue
            D.append(i)
            if len(D) > 2:
                return False
        if len(D) != 2 or s[D[0]] != g[D[1]] or s[D[1]] != g[D[0]]:
            return False
        return True

