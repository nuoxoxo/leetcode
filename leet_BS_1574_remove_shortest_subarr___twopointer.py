class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        if n == 0 or n == 1:
            return 0
        R = n - 1
        while R > 0 and arr[R - 1] <= arr[R]:
            R -= 1
        res = R
        L = 0
        while L < n:
            if L >= R:
                break
            if L > 0 and arr[L - 1] > arr[L]:
                break
            while R < n and arr[L] > arr[R]:
                R += 1
            res = min(res, R - L - 1)
            L += 1
        return res
