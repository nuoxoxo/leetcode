class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n is 1:
            if nums[0] == target:
                return 0
            else:
                return -1
        L = 0
        R = n - 1
        while L <= R:
            mp = (L + R) // 2
            val = nums[mp]
            if val == target:
                return mp
            elif val < target:
                L = mp + 1
            else:
                R = mp - 1
        return -1
