class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        N = len(s)
        if len(s) % 2 != 0:
            return False
        # L-R
        z = 0
        L, R = 0, 0
        for i in range(N):
            if locked[i] == '0':
                z += 1
            else:
                if s[i] == '(':
                    L += 1
                else:
                    R += 1
            if R > z + L:
                return False
        z = 0
        L, R = 0, 0
        for i in range(N - 1, -1, -1):
            if locked[i] == '0':
                z += 1
            else:
                if s[i] == '(':
                    L += 1
                else:
                    R += 1
            if L > z + R: # impossible > possible 
                return False
        return True

