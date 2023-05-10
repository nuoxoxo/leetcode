class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[-1 for _ in range(n)] for _ in range(n)]
        acc = 1
        U, L = 0, 0
        D, R = n - 1, n - 1
        while U <= D and L <= R:
            i = L
            while i <= R:
                res[U][i] = acc
                acc += 1
                i += 1
            U += 1

            i = U
            while i <= D:
                res[i][R] = acc
                acc += 1
                i += 1
            R -= 1
            
            i = R
            while i >= L:
                res[D][i] = acc
                acc += 1
                i -= 1
            D -= 1
            
            i = D
            while i >= U:
                res[i][L] = acc
                acc += 1
                i -= 1
            L += 1
        # print()
        return res

