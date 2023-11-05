class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        hi = max(arr)
        size = len(arr)
        if k >= size:
            return hi
        res = arr[0]
        count = 0
        for i in range(1, size):
            # print(res, arr[i], count)
            if res < arr[i]:
                res = arr[i]
                count = 1
            else:
                count += 1
            if count == k:
                return res
        return hi
