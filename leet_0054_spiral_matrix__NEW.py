class Solution:
    def spiralOrder(self, m: List[List[int]]) -> List[int]:
        res = []
        rows = len(m)
        cols = len(m[0])
        U, R, D, L = 0, cols - 1, rows - 1, 0
        while U <= D and L <= R:
            i = L
            while i <= R:
                res.append(m[U][i])
                i += 1
            U += 1
            i = U
            while i <= D:
                res.append(m[i][R])
                i += 1
            R -= 1
            if U <= D:
                i = R
                while i >= L:
                    res.append(m[D][i])
                    i -= 1
                D -= 1
            if L <= R:
                i = D
                while i >= U:
                    res.append(m[i][L])
                    i -= 1
                L += 1
        return res

