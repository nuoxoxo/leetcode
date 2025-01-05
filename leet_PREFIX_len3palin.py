class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        def sub(ss: str, s: str) -> bool:
            i = 0
            for c in s:
                if i == 3:
                    break
                if ss[i] == c:
                    i += 1
            return i == 3
        res = 0
        a, z = ord('a'), ord('z')
        for edge in range(a, z + 1):
            for mid in range(a, z + 1):
                res += sub( chr(edge) + chr(mid) + chr(edge), s)
        return res
