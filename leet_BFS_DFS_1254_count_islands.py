class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        return [
            self.Solution_DFS_Floodfill, # T(RC), S(1)
            self.Solution_BFS,
        ][ random.randint(0,1) ]( grid )

    def Solution_BFS (self, grid: List[List[int]]) -> int:
        print('/Solution_BFS')
        R, C = len(grid), len(grid[0])
        DR = [-1,0,1,0]
        DC = [0,-1,0,1]
        seen = set()

        def valid_and_unexplored(coor) -> bool:
            r, c = coor
            return -1 < r < R and -1 < c < C and grid[r][c] == 0 and coor not in seen

        def BFS(coor) -> None:
            if not valid_and_unexplored (coor):
                return
            dq = deque()
            dq.append( coor )
            seen.add( coor )
            # r, c = coor
            while dq:
                r, c = dq.popleft()
                for dr, dc in zip(DR, DC):
                    rr, cc = r + dr, c + dc
                    if valid_and_unexplored( (rr,cc) ):
                        dq.append( (rr, cc) )
                        seen.add ( (rr, cc) )
        E = [(0, c) for c in range(C)] + \
            [(R - 1, c) for c in range(C)] + \
            [(r, 0) for r in range(R)] + \
            [(r, C - 1) for r in range(R)] # edges
        for e in E:
            BFS(e)
        res = 0
        for r in range(1, R - 1): # inland
            for c in range(1, C - 1):
                if valid_and_unexplored((r,c)):
                    res += 1
                    BFS ((r, c))
        return res

    def Solution_DFS_Floodfill (self, grid: List[List[int]]) -> int:
        print('/Solution_DFS_Floodfill')
        R, C = len(grid), len(grid[0])
        if R == 0 or C == 0:
            return 0
        DR = [-1,0,1,0]
        DC = [0,-1,0,1]

        def DFS (r, c) -> None:
            if -1 < r < R and -1 < c < C and grid[r][c] == 0:
                grid[r][c] = 1
                for dr, dc in zip(DR, DC):
                    DFS (r + dr, c + dc)

        res = 0
        # Simplified
        E = [(0, c) for c in range(C)] + \
            [(R - 1, c) for c in range(C)] + \
            [(r, 0) for r in range(R)] + \
            [(r, C - 1) for r in range(R)] # edges
        for r, c in E:
            DFS (r, c)
        # verbose
        """
        for c in range(C): # flood the top & bottoml edges
            DFS(0, c)
            DFS(R - 1, c)
        for r in range(R): # flood L & R edges
            DFS(r, 0)
            DFS(r, C - 1)
        """
        for r in range(1, R - 1): # flood the inland
            for c in range(1, C - 1):
                if grid[r][c] == 0 and (r, c):
                    res += 1
                    DFS (r, c)
        return res
