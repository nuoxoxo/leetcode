class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        res = 0
        MOD = 10**9+7
        eve,odd = 1,0
        prefix = 0
        for n in arr:
            prefix += n
            if prefix % 2 == 0:
                eve += 1
                res += odd
            else:
                odd += 1
                res += eve
            res %= MOD
        return res
            
