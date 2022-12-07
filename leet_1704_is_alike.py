class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        a = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        n = len(s)
        ll, rr = 0, 0
        for i in range(n // 2):
            l = s[i]
            r = s[i + n // 2]
            if l in a:
                ll += 1
            if r in a:
                rr += 1
        return rr == ll
