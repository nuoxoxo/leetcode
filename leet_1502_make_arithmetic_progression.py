class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        s = len(arr)
        if s < 3:
            return True
        i = 0
        arr.sort()
        while i < s - 2:
            if arr[i] - arr[i + 1] != arr[i + 1] - arr[i + 2]:
                return False
            i += 1
        return True
