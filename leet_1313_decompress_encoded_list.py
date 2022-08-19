class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        L = len(nums)
        temp = []
        res = []
        for i in range(0, L, 2):
            temp.append([nums[i + 1]] * nums[i])
        for t in temp:
            res += t
        return res
