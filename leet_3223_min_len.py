class Solution:
    def minimumLength(self, s: str) -> int:
        D = collections.Counter(s)
        N = len(s)
        rm = 0
        for v in D.values():
            if v % 2 == 0:
                rm += v - 2 # rmv all val-2 number of char c
            else:
                rm += v - 1
        return N - rm
