class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        l = len(strs[0])
        a = ['' for _ in range(l)]
        for i in range(l):
            for s in strs:
                a[i] += s[i]
        r = 0
        for s in a:
            if s != ''.join(sorted(s)):
                r += 1
        return r
