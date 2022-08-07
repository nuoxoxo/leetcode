class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        s3 = len(nums) - 1
        count = 0
        nums.sort()
        while s3 > 1:
            s1 = 0
            s2 = s3 - 1
            while s1 < s2:
                if nums[s1] + nums[s2] > nums[s3]:
                    count += s2 - s1
                    s2 -= 1
                else:
                    s1 += 1
            s3 -= 1
        return count
