class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        r = []
        for i in range(len(index)):
            r.insert(index[i], nums[i])
        return r
