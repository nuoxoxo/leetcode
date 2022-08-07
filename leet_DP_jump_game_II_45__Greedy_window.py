class Solution:
    def jump(self, nums: List[int]) -> int:
        """
        [0]
        [1,1,1,1]
        [2,1,1,1,1]
        [2,3,1,1,4]
        [2,3,0,1,4]
        """
        size = len(nums)
        if size == 1:
            return 0
        if nums[0] >= size:
            return 1
        L = R = steps = 0
        while R < size - 1:
            reach = 0
            i = L
            while i < R + 1:
                reach = max(reach, i + nums[i])
                i += 1
            L = R + 1
            R = reach
            steps += 1
        return steps
