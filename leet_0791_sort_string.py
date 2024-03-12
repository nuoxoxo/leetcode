class Solution:
    def customSortString(self, order: str, s: str) -> str:
        return [
            self.Using_dict, # Faster
            self.Using_set,
        ][ 0 ]( order, s )

    def Using_dict(self, order: str, s: str) -> str:
        D = dict(Counter(s))
        res = []
        for c in order:
            if c not in D:
                continue
            for _ in range(D[c]):
                res.append(c)
            D[c] = 0
        for char, times in D.items():
            for _ in range(times):
                res.append(char)
        return ''.join(res)

    def Using_set(self, order: str, s: str) -> str:
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
