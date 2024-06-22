class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        N = len(nums)
        Q = deque()
        res = 0
        L = 0
        for R in range(N):
            # add to Q if odd
            if nums[R] % 2 == 1:
                Q.append(R)
            while len(Q) > k:
                L = Q.popleft() + 1
            if len(Q) == k:
                diff = Q[0] - L + 1
                res += diff
        return res
