class Solution:
    def countCollisions(self, dir: str) -> int:
        n = len(dir)
        res = 0
        i = 0
        j = n - 1
        while i < n and dir[i] == 'L':
            i += 1
        while j > -1 and dir[j] == 'R':
            j -= 1
        while i <= j:
            if dir[i] != 'S':
                res += 1
            i += 1
        return res
        
