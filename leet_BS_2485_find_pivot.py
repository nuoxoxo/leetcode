class Solution:
    def pivotInteger(self, n: int) -> int:
        l, r = 1, n
        while l <= r:
            mid = (r - l) // 2 + l
            print(mid)
            L, R = 0, 0
            for i in range(mid + 1):
                L += i
            for i in range(mid, n + 1):
                R += i
            if L == R:
                return mid
            if L < R:
                l = mid + 1
            else:
                r = mid - 1
        return -1
