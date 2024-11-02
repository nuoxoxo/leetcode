class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        N = len(code)
        res = [0] * N
        if k == 0:
            return res
        fact = 1
        if k < 0: fact = -1
        for i in range(N):
            for j in range(k * fact):
                res[i] += code[ (i + fact * j + fact * 1 + N) % N ]
        return res
