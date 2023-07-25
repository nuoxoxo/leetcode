class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        L = 0
        R = len(arr) - 1
        while L <= R:
            mid = (L + R) // 2
            if arr[mid - 1] < arr[mid] > arr[mid + 1]:
                return mid
            if arr[mid] < arr[mid + 1]:
                L = mid + 1
            elif arr[mid] > arr[mid + 1]:
                R = mid - 1
        return L # return R also works
