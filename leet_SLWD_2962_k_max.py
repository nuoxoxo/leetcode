class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        countingmx = 0
        res = 0
        l = 0
        for r in range(len(nums)):
            if nums[r] == mx:
                countingmx += 1
            if countingmx >= k:
                while countingmx > k:
                    if nums[l] == mx:
                        countingmx -= 1
                    l += 1
                while l < r and nums[l] != mx:
                    l += 1
                res += l + 1
                # l+1 is the degree of freedom to go leftwards beyond l
        return res
