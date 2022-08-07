class Solution:

    original = []

    def __init__(self, nums: List[int]):
        self.original = nums

    def reset(self) -> List[int]:
        return self.original

    def shuffle(self) -> List[int]:
        res = self.original.copy() 
        for i in range(len(self.original) - 1, -1, -1):
            r = randint(0, i)
            res[i], res[r] = res[r], res[i]
        return res


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
