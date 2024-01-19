class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        return [
            self.Solution_DP_extra_matrix,
            self.Solution_DP_in_place,
        ][ random.randint(0,1) ]( matrix )

    # T( R x C ), S( 1 )
    def Solution_DP_in_place(self, matrix: List[List[int]]) -> int:
        R, C = len(matrix), len(matrix[0])
        for r in range(1, R):
            for c in range(C):
                temp = []
                for dc in range(-1, 2):
                    cc = c + dc
                    if -1 < cc < C:
                        temp.append(matrix[r - 1][cc] + matrix[r][c])
                matrix[r][c] = min( temp )
            # print('/row '+str(r),matrix[r])
        return min(matrix[-1])

    # T( R x C ), S( R x C )
    def Solution_DP_extra_matrix(self, matrix: List[List[int]]) -> int:
        print('\Solution_DP_extra_matrix')
        R, C = len(matrix), len(matrix[0])
        DP = [[1e9 for _ in range(C)] for _ in range(R)]
        DP[0] = matrix[0].copy()
        for r in range(1, R):
            for c in range(C):
                for dc in range(-1, 2):
                    cc = c + dc
                    if -1 < cc < C:
                        DP[r][c] = min(DP[r - 1][cc] + matrix[r][c], DP[r][c])
        return min(DP[-1])
