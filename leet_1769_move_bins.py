class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        # O: n^2
        N = len(boxes)
        res = [0] * N
        for L in range(N):
            for R in range(N):
                if boxes[R] == '1':
                    res[L] += abs(R - L)
        return res
