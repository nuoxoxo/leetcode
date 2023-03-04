class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        res = 0
        L_found, R_found = False, False
        L, R = 0, 0
        start = 0
        
        for i in range(len(nums)):
            if nums[i] < minK or nums[i] > maxK:
                L_found = False
                R_found = False
                start = i + 1

            if nums[i] == minK:
                L_found = True
                L = i

            if nums[i] == maxK:
                R_found = True
                R = i

            if L_found and R_found:
                res += min(L, R) - start + 1
        return res
