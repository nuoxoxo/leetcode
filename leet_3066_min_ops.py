class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        res = 0
        heapq.heapify(nums)
        while len(nums) > 1:
            if nums[0] >= k:
                return res
            res += 1
            l,r = heapq.heappop(nums), heapq.heappop(nums)
            heapq.heappush(nums, l * 2 + r)
        assert nums
        if nums[0] < k:
            return -1
        return res
