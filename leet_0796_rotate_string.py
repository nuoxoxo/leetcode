class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if s == goal: return True
        N = len(goal)
        if N != len(s): return False
        while N > -1:
            left = goal[0]
            goal = goal[1:] + left
            # print(s, goal, left)
            if s == goal: return True
            N -= 1
        return False
