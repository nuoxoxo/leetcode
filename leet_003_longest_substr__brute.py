class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        L = len(s)
        if L == 1 or L == 0:
            return L
        res = 0;
        i = 0
        while i < L:
            E = {}
            j = i
            while j < L:
                c = s[j]
                if c not in E:
                    E[c] = 1
                else:
                    break
                j += 1
            res = max(res, len(E))
            i += 1
        return res
