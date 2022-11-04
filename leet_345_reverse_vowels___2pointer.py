class Solution:
    def reverseVowels(self, s: str) -> str:
        v = ['a','e','i','o','u','A','E','I','O','U']
        ss = list(s)
        i, j = 0, len(s) - 1
        while i < j:
            while i < j and not s[i] in v:
                i += 1
            while i < j and s[j] not in v:
                j -= 1
            if i < j:
                ss[i], ss[j] = ss[j], ss[i]
            i += 1
            j -= 1
        return ''.join(ss)
