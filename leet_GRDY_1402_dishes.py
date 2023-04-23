class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        n = len(satisfaction)
        tmp = 0
        res = 0
        cur = 0
        i = n - 1
        while i > -1:
            cur += tmp + satisfaction[i]
            if cur < 1:
                break
            tmp += satisfaction[i]
            res = res if res > cur else cur
            i -= 1
        return res
