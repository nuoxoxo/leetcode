class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        L = len(s)
        i = 0
        c = 0
        while i < L - k + 1:
            tmp = int(s[i: i + k])
            if tmp > 0 and num % tmp == 0:
                c += 1
            i += 1
        return c
