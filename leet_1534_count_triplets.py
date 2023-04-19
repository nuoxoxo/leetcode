class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        res = 0
        L = len(arr)
        for i in range(L - 2):
            for j in range(i + 1, L - 1):
                for k in range(j + 1, L):
                    if all([ abs(arr[i] - arr[j]) <= a,
                            abs(arr[j] - arr[k]) <= b, 
                            abs(arr[k] - arr[i]) <= c ]):
                        res += 1
        return res
