class Solution:
    def minDifference(self, nums: List[int]) -> int:
        return [
            bruteforce,
            # alternative
        ][0](nums)

def bruteforce(nums: List[int]) -> int:
    N = len(nums)
    if N < 5:
        return 0
    nums.sort(reverse=True)
    return min([
        nums[3] - nums[N - 1],
        nums[2] - nums[N - 2],
        nums[1] - nums[N - 3],
        nums[0] - nums[N - 4],
    ])

def alternative(nums: List[int]) -> int:
    N = len(nums)
    if N < 5:
        return 0
    res = 1e20
    nums.sort(reverse=True)
    for i in range(0, 4):
        res = min(res, nums[i] - nums[N - 4 + i])
    return res
