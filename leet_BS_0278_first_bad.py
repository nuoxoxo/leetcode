# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left, right, res = 1, n, n
        while left <= right:
            mid = (left + right) // 2
            if isBadVersion(mid):
                res = mid
                right = res - 1
            else:
                left = mid + 1
        return res
