class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        return [
            # Using_heapq,
            Sort_and_swap,
        ][0](nums)

def Sort_and_swap(nums: List[int]) -> List[int]:
    nums.sort()
    for i in range(0, len(nums), 2):
        nums[i], nums[i + 1] = nums[i + 1], nums[i]
    return nums

def Using_heapq(nums: List[int]) -> List[int]:
    res = []
    heapq.heapify(nums)
    while nums:
        a, b = heapq.heappop(nums), heapq.heappop(nums)
        res.append(b)
        res.append(a)
    return res
