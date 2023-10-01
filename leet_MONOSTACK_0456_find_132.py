class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        """
        '132' ~ L  mid  R
        """
        d = []
        mid = -1e9
        for i in range(len(nums) - 1, -1, -1):
            L = nums[i]
            if L < mid:
                return True
            while d and L > d[-1]:
                mid = d.pop()
            d.append(L)
        return False
