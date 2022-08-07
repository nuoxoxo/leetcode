class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return [[matrix[_][__] for _ in range(len(matrix))] for __ in range(len(matrix[0]))]
