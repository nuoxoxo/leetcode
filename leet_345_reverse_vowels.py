class Solution:
    def reverseVowels(self, s: str) -> str:
        v = ['a','e','i','o','u','A','E','I','O','U']
        idx, c = [], []
        ss = list(s)
        # print(ss)
        for i in range(len(s)):
            if s[i] in v:
                idx.append(i)
                c.append(s[i])
        c = c[::-1]
        i = 0
        for n in idx:
            ss[n] = c[i]
            i += 1
        return ''.join(ss)
        
