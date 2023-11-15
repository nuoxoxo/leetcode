class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        # way 1 : simple approach
        """
        arr.sort()
        res = 1
        for n in arr:
            print(res, res + 1, n)
            res = min(res + 1, n)
        return res
        """
        # way 2 : greedy
        arr.sort()
        arr[0] = 1
        res = 1
        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                arr[i] = arr[i - 1] + 1
            res = max(arr[i], res)
        return res
