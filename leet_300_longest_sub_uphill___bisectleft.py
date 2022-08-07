class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        temp = []
        for num in nums:
            i = bisect.bisect_left(temp, num)
            if i != len(temp):
                temp[i] = num
            else:
                temp.append(num)
        return len(temp)
