class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        return [
            # Sliding_window,
            Sliding_window_2,
        ][0](s)

def Sliding_window_2(s:str) -> int:
    N = len(s)
    a,b,c = [N] * 3
    # print(a,b,c)
    res = 0
    for i,char in enumerate(s):
        match char:
            case 'a':
                a = i
            case 'b':
                b = i
            case 'c':
                c = i
        if a < N and b < N and c < N:
            res += min(a,b,c) + 1
    return res

def Sliding_window(s:str) -> int:
    D = collections.defaultdict(int)
    N = len(s)
    L = 0
    res = 0
    for R,c in enumerate(s):
        D[c] += 1
        while D['a'] > 0 and D['b'] > 0 and D['c'] > 0:
            lc = s[L]
            D[lc] -= 1
            L += 1
            res += N - R
    return res

