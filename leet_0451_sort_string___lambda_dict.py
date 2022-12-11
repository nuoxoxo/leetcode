class Solution:
    def frequencySort(self, s: str) -> str:
        D = dict()
        a = []
        r = ''
        for c in s:
            if c in D:
                D[c] += 1
            else:
                D[c] = 1
        D = dict(sorted(D.items(), key=lambda it: it[1], reverse=True))
        for k, v in D.items():
            for i in range(v):
                r += k
        return r
