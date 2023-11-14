class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        def isSS(ss: str, s: str) -> bool:
            end = 0
            for c in s:
                if end > 2:
                    break
                if ss[end] == c:
                    end += 1
            return end == 3
        res = 0
        a = ord('a')
        z = ord('z')
        for edge in range(a, z + 1):
            for mid in range(a, z + 1):
                ss = chr(edge) + chr(mid) + chr(edge)
                if isSS(ss, s):
                    res += 1
        return res
