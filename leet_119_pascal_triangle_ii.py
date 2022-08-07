class Solution:
    def getRow(self, row: int) -> List[int]:
        if row is 0:
            return [1]
        if row is 1:
            return [1, 1]
        p = [[] for _ in range(row + 1)]
        p[0] = [1]
        p[1] = [1, 1]
        for i in range(2, row + 1):
            for j in range(i + 1) :
                if j is 0 or j is i:
                    p[i].append(1)
                else:
                    p[i].append(p[i - 1][j - 1] + p[i - 1][j])
        return p[row]
