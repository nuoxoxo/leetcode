class Solution:
    def smallestSubsequence(self, s: str) -> str:
        seen = [False] * 26
        count = [0] * 26
        res = ''
        a = ord('a')
        for c in s:
            count[ord(c) - a] += 1
        for c in s:
            asc = ord(c)
            if not seen[asc - a]:
                while res != '' and ord(res[-1]) > asc and count[ord(res[-1]) - a] > 1:
                    count[ord(res[-1]) - a] -= 1
                    seen[ord(res[-1]) - a] = False
                    res = res[:-1]
                seen[asc - a] = True
                res += c
            else:
                count[asc - a] -= 1
        return res

