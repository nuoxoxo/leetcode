class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        N = len(nums)
        Q = deque()
        curr = False # to flip or not
        res = 0
        for i, n in enumerate(nums):
            if Q and Q[0] == i:
                curr = not curr
                Q.popleft()
            # once we're at a 0, flip next k bits
            if n == curr:
                # flip next k bits
                curr = not curr
                Q.append(i + k)
                res += 1
        if Q and Q[0] == N:
            Q.popleft()
        if Q:
            return -1
        return res
