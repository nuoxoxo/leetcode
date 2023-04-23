class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i = 0
        j = len(matrix[0]) - 1
        while i < len(matrix) and j > -1:
            n = matrix[i][j]
            if target > n:
                i += 1
            elif target < n:
                j -= 1
            else:
                return True
        return False
