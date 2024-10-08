class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        N = len(s1)
        D = collections.Counter(s1)
        for i in range(len(s2) - N + 1 ):
            sub = s2[i : i + N]
            cp = copy.deepcopy(D)
            for c in sub:
                if c in D:
                    cp[c] -= 1
            ok = True
            for v in cp.values():
                if v != 0:
                    ok = False
                    break
            if ok:
                return True
        return False
