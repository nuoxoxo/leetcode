class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        C = len(maze[0])
        R = len(maze)
        res = 1
        d = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        D = []
        D.append([entrance[0], entrance[1]])
        maze[entrance[0]][entrance[1]] = '+'
        while len(D) != 0:
            n = len(D)
            while n != 0:
                temp_x, temp_y = D[0][0], D[0][1]
                D.pop(0)
                for i in range (4):
                    x = d[i][0] + temp_x
                    y = d[i][1] + temp_y
                    if x < R and x > -1 and y < C and y > -1 and maze[x][y] == '.':
                        if x == 0 or y == 0 or x == R - 1 or y == C - 1:
                            return res
                        else:
                            maze[x][y] = '+'
                            D.append([x, y])
                n -= 1
            res += 1
        return -1
