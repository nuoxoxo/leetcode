class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        if len(s) < k:
            return s
        E = []
        for c in s:
            # print(E)
            if E and E[-1][0] == c:
                tup = E.pop()
                E.append((tup[0], tup[1] + 1))
            else:
                E.append((c, 1))
            if E[-1][1] == k:
                E.pop()
        return ''.join(e[0] * e[1] for e in E)
