class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        return [_ for _ in nums if _ % 2 == 0] + [_ for _ in nums if _ % 2 == 1]
