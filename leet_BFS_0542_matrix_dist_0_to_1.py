class Solution:
    def updateMatrix(self, M: List[List[int]]) -> List[List[int]]:
        dx = [0,1,0,-1]
        dy = [-1,0,1,0]
        c = len(M[0])
        r = len(M)
        D = [ [-1] * c for _ in range(r)] 
        E = deque()
        i = 0
        while i < r:
            j = 0
            while j < c:
                if M[i][j] == 0:
                    E.append((i, j))
                    D[i][j] = M[i][j]
                j += 1
            i += 1
        while E:
            temp = E.popleft()
            i = 0
            while i < 4:
                x = temp[0] + dx[i]
                y = temp[1] + dy[i]
                if x>-1 and y>-1 and x<r and y<c and M[x][y] is 1 and D[x][y] is -1:
                    D[x][y] = D[temp[0]][temp[1]] + 1
                    E.append((x, y))
                i += 1
        return D
