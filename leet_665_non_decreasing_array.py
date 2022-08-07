class Solution:
    def checkPossibility(self, n: List[int]) -> bool:
        moveup = i = 0
        for i in range(1, len(n)):
            if n[i - 1] <= n[i]:
                continue
            if moveup == 1:
                return False
            if i > 1:
                if n[i - 2] == n[i - 1] or n[i - 2] > n[i]:
                    n[i] = n[i - 1]
                else:
                    n[i - 1] = n[i - 2]
            moveup += 1
        return True
