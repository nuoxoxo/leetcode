class Solution:
    def maxConsecutiveAnswers(self, s: str, k: int) -> int:
        size = len(s)
        res = 0
        T, F, L, R = 0, 0, 0, 0
        while R < size:
            if s[R] == 'T':
                T += 1
            else:
                F += 1
            while T > k and F > k:
                if s[L] == 'T':
                    T -= 1
                else:
                    F -= 1
                L += 1
            res = max(res, R - L + 1)
            R += 1
        return res
