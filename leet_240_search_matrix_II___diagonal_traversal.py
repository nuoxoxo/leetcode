class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        j = len(matrix[0]) - 1
        r = len(matrix)
        i = 0
        while i < r and j > -1:
            n = matrix[i][j]
            if target == n:
                return True
            if target > n:
                i += 1
            else:
                j -= 1
        return False
        
