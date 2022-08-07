class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        D = {}
        for i, num in enumerate(numbers):
            if num in D:
                return [D[num] + 1, i + 1]
            D[target - num] = i
