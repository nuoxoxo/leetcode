class Solution:
    def makeGood(self, s: str) -> str:
        a = list(s)
        i = 0
        j = -1
        while i < len(s):
            if j == -1 or abs(ord(a[i]) - ord(a[j])) != 32:
                j += 1
                a[j] = a[i]
            else:
                j -= 1
            i += 1
        return ''.join(a[0:j + 1])

