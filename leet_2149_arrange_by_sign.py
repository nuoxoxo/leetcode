class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        return [
            self.Solution_fixed_size_list,
            # self.Solution_2_deques,
        ][0](nums)

    def Solution_fixed_size_list(self, nums: List[int]) -> List[int]:
        N = len(nums)
        res = [None] * N
        posindex, negindex = 0, 1
        for n in nums:
            if n < 0:
                res[ negindex ] = n
                negindex += 2
            else:
                res[ posindex ] = n
                posindex += 2
        return res

    def Solution_2_deques(self, nums: List[int]) -> List[int]:
        P, N = deque(), deque()
        for n in nums:
            P.append(n) if n > 0 else N.append(n)
        res = []
        while P and N:
            res.append(P.popleft())
            res.append(N.popleft())
        return res
