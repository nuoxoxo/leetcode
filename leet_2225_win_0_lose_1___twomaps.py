class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        w = {}
        l = {}
        r1 = []
        r2 = []
        for m in matches:
            a, b = m[0], m[1]
            if a in w:
                w[a] += 1
            else:
                w[a] = 1
            if b in l:
                l[b] += 1
            else:
                l[b] = 1
        for n in w:
            if n not in l:
                r1.append(n)
        for n in l:
            if l[n] == 1:
                r2.append(n)
        return [ sorted(r1), sorted(r2) ]
