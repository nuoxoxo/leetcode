class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        L = 0
        R = num
        while L <= R:
            mid = (R + L) // 2
            msq = mid ** 2
            if msq < num:
                L = mid + 1
            elif msq > num :
                R = mid - 1
            else:
                return True
        return False
