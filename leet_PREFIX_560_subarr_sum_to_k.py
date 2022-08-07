class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        d = {}
        d[0] = 1
        total = 0
        count = 0
        for n in nums:
            total += n
            if total - k in d:
                count += d[total - k]
            if total in d:
                d[total] += 1
            else:
                d[total] = 1
        return count
        
