class Solution:
    def specialArray(self, nums: List[int]) -> int:
        return [
            # Bruteforce_bisect_left,
            # Bruteforce_bisect_left_DIY,
            Without_lower_bound,
        ][0](nums)

def Without_lower_bound(nums: List[int]) -> int:
    nums.sort()
    N = len(nums)
    x = 1
    # for x in range(1, N):
    while x < N:
        idx = N - x
        if nums[idx - 1] < x and nums[idx] >= x:
            return x
        x += 1
    if x <= nums[0]:
        assert x == N # bug - why not working
        return N
    return -1

def Bruteforce_bisect_left(nums: List[int]) -> int:
    nums.sort()
    N = len(nums)
    for curr in range(N + 1):
        L = bisect_left(nums, curr)
        if curr == N - L:
            return curr
    return -1

def Bruteforce_bisect_left_DIY(nums: List[int]) -> int:
    nums.sort()
    N = len(nums)
    for curr in range(N + 1):
        L, R = 0, N
        while L < R:
            mid = (L + R) // 2
            n = nums[mid]
            if n < curr:
                L = mid + 1
            else:
                R = mid
        if curr == N - L:
            return curr
    return -1
