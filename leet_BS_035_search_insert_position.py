class Solution:
    def searchInsert(self, a: List[int], target: int) -> int:
        n = len(a)
        L, R = 0, n - 1
        while L <= R:
            mid = (R - L) // 2 + L
            val = a[mid]
            if val == target:
                return mid
            if val < target:
                L = mid + 1
            else:
                R = mid - 1
        return L
