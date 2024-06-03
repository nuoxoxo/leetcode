class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        return [Iterative, Recursive][0](s, t)

def Recursive(s: str, t: str) -> int:
    def go(i, it) -> int:
        if it == len(t):
            return 0
        if i == len(s):
            return len(t) - it
        if s[i] == t[it]:
            return go(i + 1, it + 1)
        return go(i + 1, it)
    return go(0, 0)

def Iterative(s: str, t: str) -> int:
    it = 0
    for i in range(len(s)):
        if s[i] == t[it]:
            it += 1
            if it == len(t):
                return 0
    return len(t) - it

