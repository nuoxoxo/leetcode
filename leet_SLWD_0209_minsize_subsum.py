# new

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if target in nums:
            return 1
        L = 0
        R = 0
        found = False
        res = 1e9
        temp = 0

        # outer loop: add an element from the right
        while R < len(nums):
            temp += nums[R]
            if temp >= target:
                found = True

            # inner loop: trim from the left
            while temp >= target:
                res = min(res, R - L + 1)
                temp -= nums[L]
                L += 1
            R += 1

        return 0 if not found else res


"""
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        if target in nums:
            return 1
        yes = False
        res = 1e9
        fast = 0
        slow = 0
        add = 0
        while fast < len(nums):
            add += nums[fast]
            while add >= target:
                yes = True
                res = min(res, fast - slow + 1)
                add -= nums[slow]
                slow += 1
            fast += 1
        if yes:
            return res
        return 0
"""

