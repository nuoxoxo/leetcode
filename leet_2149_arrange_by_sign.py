class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        P, N = deque(), deque()
        for n in nums:
            P.append(n) if n > 0 else N.append(n)
        res = []
        while P and N:
            res.append(P.popleft())
            res.append(N.popleft())
        return res
