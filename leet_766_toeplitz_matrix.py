class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        first = matrix[0]
        n = len(matrix[0])
        m = len(matrix)
        if m is 1 or n is 1:
            return True
        for i in range(1, m):
            current = matrix[i][1:]
            first.pop()            
            if (first != current):
                return False
            first = matrix[i]
        return True
