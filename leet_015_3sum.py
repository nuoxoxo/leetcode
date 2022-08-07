class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3:
            return []
        nums.sort()
        res = []
        for i in range(n - 2):
            if i == 0 or nums[i] ^ nums[i - 1]:
                j = i + 1
                k = n - 1
                while j < k:
                    t = nums[i] + nums[j] + nums[k]
                    if t < 0:
                        j += 1
                    elif t > 0:
                        k -= 1
                    else:
                        res.append( [ nums[i], nums[j], nums[k] ] );
                        while j < k and nums[j + 1] == nums[j]:
                            j += 1
                        while j < k and nums[k - 1] == nums[k]:
                            k -= 1
                        j += 1
                        k -= 1
        return res
