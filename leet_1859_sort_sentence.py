class Solution:
    def sortSentence(self, s: str) -> str:
        r = [''] * 9
        start = 0
        for i in range(0, len(s) + 1):
            if i == len(s) or s[i] == ' ':
                temp = s[start : i]
                temp = temp[:-1]
                r[int(s[i - 1]) - 1] = temp + ' '
                start = i + 1
        res = ''
        for t in r:
            res += t
        return res[:-1]
