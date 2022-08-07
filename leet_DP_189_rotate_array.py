class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        L = len(nums)
        k %= L
        if k == 0:
            return
        i = L - k
        A = []
        while i < L:
            A.append(nums[i])
            i += 1
        i = 0
        while i < L - k:
            A.append(nums[i])
            i += 1
        nums[:] = A
