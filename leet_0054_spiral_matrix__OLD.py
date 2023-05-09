class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        hicol = len(matrix[0])
        hirow = len(matrix)
        area = hicol * hirow
        if area is 1:
            return matrix[0]
        
        locol = -1
        lorow = -1
        count = 0
        r = 0
        c = 0
        g = []
        while True:
            if count is not 0:
                c += 1
            while c < hicol:
                g.append(matrix[r][c])
                count += 1
                c += 1
            if count is area:
                break
            c -= 1
            r += 1
            while r < hirow:
                g.append(matrix[r][c])
                count += 1
                r += 1
            if count is area:
                break
            r -= 1
            c -= 1
            while c > locol:
                g.append(matrix[r][c])
                count += 1
                c -= 1
            if count is area:
                break
            c += 1
            r -= 1
            hirow -= 1
            hicol -= 1
            lorow += 1
            locol += 1
            while r > lorow:
                g.append(matrix[r][c])
                count += 1
                r -= 1
            if count is area:
                break
            r += 1
        return g
