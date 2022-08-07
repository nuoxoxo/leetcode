class Solution:
    def twoSum(self, n: List[int], target: int) -> List[int]:
        r = len(n) - 1
        if (r == 1):
            return [1, 2]
        i = 0
        while i < r:
            t = n[i] + n[r]
            if t == target:
                break
            if t > target:
                r -= 1
            else:
                i += 1
        return [i + 1, r + 1]
