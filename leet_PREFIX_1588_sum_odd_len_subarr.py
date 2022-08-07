class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        size = len(arr)
        res = 0
        for i in range(size):
            tmp = 0
            j = 0
            while i + j < size:
                tmp += sum(arr[i:i + j + 1])
                j += 2
            res += tmp
        return res
