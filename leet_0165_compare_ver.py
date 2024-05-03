class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        return [
            # Space_heavy_normalization,
            Linear_time,
        ][0](version1, version2)

def Linear_time(v1: str, v2: str) -> int:
    size1, size2 = len(v1), len(v2)
    l, r = 0, 0
    while l < size1 or r < size2:
        # LEFT
        L = 0
        ll = l
        while ll < size1 and v1[ll] != '.':
            ll += 1
        w = v1[l : ll]
        if w != '':
            L = int(w)
        # RIGHT
        R = 0
        rr = r
        while rr < size2 and v2[rr] != '.':
            rr += 1
        w = v2[r : rr]
        if w != '':
            R = int(w)
        # EVAL
        if L < R:
            return -1
        if L > R:
            return 1
        l, r = ll + 1, rr + 1
    return 0

def Space_heavy_normalization(version1: str, version2: str) -> int:
    L = [int(_) for _ in version1.split('.')]
    R = [int(_) for _ in version2.split('.')]
    while len(L) < len(R):
        L.append(0)
    while len(L) > len(R):
        R.append(0)
    for l, r in zip(L, R):
        if l < r:
            return -1
        elif l > r:
            return 1
    return 0
