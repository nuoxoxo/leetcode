class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        side = len(matrix)
        g = []
        for i in range(side):
            for j in range(side):
                g.append(matrix[i][j])
        return sorted(g)[k - 1]
