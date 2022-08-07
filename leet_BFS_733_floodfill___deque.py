class Solution:
    def floodFill(self, img: List[List[int]], x: int, y: int, nc: int) -> List[List[int]]:
        oc = img[x][y]
        if oc == nc:
            return img
        c = len(img[0])
        r = len(img)
        dq = deque()
        dq.append((x, y))
        while len(dq) != 0:
            p = dq.popleft()
            L, R = p[0], p[1]
            img[L][R] = nc
            if (L + 1 < r and img[L + 1][R] == oc):
                dq.append((L + 1, R))
            if (L - 1 > -1 and img[L - 1][R] == oc):
                dq.append((L - 1, R))
            if (R + 1 < c and img[L][R + 1] == oc):
                dq.append((L, R + 1))
            if (R - 1 > -1 and img[L][R - 1] == oc):
                dq.append((L, R - 1))
        return img
