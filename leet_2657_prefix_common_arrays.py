class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        N = len(A)
        res = [0] * N
        count = [0] * (N + 1)
        curr = 0
        for i in range(N):
            count[A[i]] += 1
            if count[A[i]] == 2:
                curr += 1
            count[B[i]] += 1
            if count[B[i]] == 2:
                curr += 1
            res[i] = curr
        return res
