class Solution:
    def customSortString(self, order: str, s: str) -> str:
        S, O = set(s), set(order)
        R = []
        for c in list(S - O):
            R.append(c * s.count(c))
        L = []
        allchars = S | O
        for c in order:
            if c in allchars:
                n = s.count(c)
                L.append(c * n)
                S.discard(c)
        return  ''.join(L + R)
