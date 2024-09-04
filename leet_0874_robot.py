class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        D = [(0, 1), (1, 0), (0, -1), (-1, 0)] # URDL
        obs = set((x, y) for x, y in obstacles)
        curr = 0 # curr dir
        furthest = 0
        x = 0
        y = 0
        for cmd in commands:
            if cmd == -2:
                curr -= 1
                if curr < 0:
                    curr += 4
            elif cmd == -1:
                curr += 1
                if curr > 3:
                    curr -= 4
            else:
                dx, dy = D[curr]
                for k in range(cmd):
                    xx = x + dx
                    yy = y + dy
                    if (xx, yy) in obs:
                        break
                    x = xx
                    y = yy
                furthest = max(furthest, x * x + y * y)
        return furthest
