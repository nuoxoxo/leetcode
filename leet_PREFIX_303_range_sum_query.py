class NumArray:

    def __init__(self, nums: List[int]):
        self.pfs = []
        self.pfs.append(nums[0])
        self.size = len(nums)
        i = 1
        while i < self.size:
            self.pfs.append(nums[i])
            self.pfs[i] += self.pfs[i - 1]
            i += 1

    def sumRange(self, left: int, right: int) -> int:
        if left > self.size - 1:
            return 0
        r = right if right < self.size - 1 else self.size - 1
        res = self.pfs[r]
        if left is 0:
            return res
        return res - self.pfs[left - 1]

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
