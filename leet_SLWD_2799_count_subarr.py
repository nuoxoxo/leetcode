class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        N = len(nums)
        L, R = 0,0
        S = set(nums)
        UN = len(S)
        D = collections.defaultdict(int)
        res = 0
        while R < N:
            D[nums[R]] += 1
            while len(D) == UN:
                D[nums[L]] -= 1
                res += N - R
                if D[nums[L]] == 0:
                    D.pop(nums[L])
                L += 1
            R += 1
        return res

