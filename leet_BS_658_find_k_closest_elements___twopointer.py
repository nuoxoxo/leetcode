class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        n = len(arr)
        right = n - 1
        left = 0
        while left < right and n > k:
            if abs(arr[left] - x) > abs(arr[right] - x):
                left += 1
            else:
                right -= 1
            n -= 1
        res = []
        while left <= right:
            res.append(arr[left])
            left += 1
        return res
