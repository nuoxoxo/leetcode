class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        # way 1:
        #   if items are the same on the left of i then res += how many on the right
        #   it's like counting backwards
        """
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                res += len(nums) - i
        return res
        """

        # way 2
        #   each time a diff item appears, it increases the 'distance' degree
        #   add it all up at each loop
        dis = 0
        for i in range(1, len(nums)):
            if nums[i] ^ nums[i - 1]:
                dis += 1
            res += dis
        return res
