class Solution:
    def minimumSteps(self, s: str) -> int:
        # cases
        #   "11000111"
        #   "01010001"
        return [
            # greedy,
            two_pointers,
        ][0](s)

def two_pointers(s: str) -> int:
    res, L, R = 0, 0, 0
    while R < len(s):
        if s[R] == '0':
            res += R - L
            L += 1
        R += 1
    return res

def greedy(s: str) -> int:
    res = 0
    tmp = 0
    for c in s:
        if c == '1':
            tmp += 1
        else:
            res += tmp
    return res
