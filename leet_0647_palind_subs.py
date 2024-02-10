class Solution:
    def countSubstrings(self, s: str) -> int:
        L = len(s)
        if L == 0 or L == 1:
            return L
        c = 0
        for i in range(L):  # odd
            j = k = i
            while j > -1 and k < L:
                if s[j] == s[k]:
                    c += 1
                    j -= 1
                    k += 1
                else:
                    break
        for i in range(L):  # even
            j = i
            k = i + 1
            while j > -1 and k < L:
                if s[j] == s[k]:
                    c += 1
                    j -= 1
                    k += 1
                else:
                    break
        return c
