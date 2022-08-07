class NumArray:
    size = 0
    arr = []
    def __init__(self, nums: List[int]):
        self.size = len(nums)
        self.arr = nums

    def sumRange(self, left: int, right: int) -> int:
        if left > self.size - 1:
            return 0
        i = left
        res = 0
        while i < self.size and i < right + 1:
            res += self.arr[i]
            i += 1
        return res

"""
["NumArray","sumRange","sumRange","sumRange"]
[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]
["NumArray","sumRange","sumRange","sumRange","sumRange","sumRange"]
[[[-4,-5]],[0,0],[1,1],[0,1],[1,1],[0,0]]
"""

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
