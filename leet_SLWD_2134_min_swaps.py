class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        # idea
        #   011100110
        #    ^^^^^  for any len-N window, we look for a min amount of 0's
        #   0101100
        #    ^^^ 
        return [
            # Double_the_nums,
            Using_modulo
        ][0](nums)

def Using_modulo(nums: List[int]) -> int:
    window = nums.count(1)
    res = window
    N = len(nums)
    ones = 0
    for R in range(N * 2):
        newR = R % N
        if nums[newR] == 1:
            ones += 1
        # BUG
        """
        L = R - window
        newL = L % N
        if newL > -1:
            if nums[newL] == 1:
                ones -= 1
            res = min(res, window - ones)
        """
        # Bugfix
        if R >= window:
            newL = (R - window) % N
            if nums[newL] == 1:
                ones -= 1
        res = min(res, window - ones)
    return res

def Double_the_nums(nums: List[int]) -> int:
    # how many 1's
    window = nums.count(1)
    res = window
    nums += nums
    N = len(nums)
    ones = 0
    for R in range(N):
        if nums[R] == 1:
            ones += 1
        L = R - window
        if L > -1:
            if nums[L] == 1:
                ones -= 1
            res = min(res, window - ones)
    return res
