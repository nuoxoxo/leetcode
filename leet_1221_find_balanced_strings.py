class Solution:
    def balancedStringSplit(self, s: str) -> int:
        cnt = 0
        res = 0
        for c in s:
            if c == 'R':
                cnt += 1
            if c == 'L':
                cnt -= 1
            if cnt == 0:
                res += 1
        return res
