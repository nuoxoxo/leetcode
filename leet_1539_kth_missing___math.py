class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        # math soln
        if k < arr[0]:
            return k
        k = k - arr[0] + 1
        i = 1
        while i < len(arr):
            diff = arr[i] - arr[i - 1]
            if diff == 1:
                i += 1
                continue
            if k < diff:
                break
            k = k - diff + 1
            i += 1
        return arr[i - 1] + k
