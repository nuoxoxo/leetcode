class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        D = defaultdict(list)
        for r in range(len(nums)):
            for c in range(len(nums[r])):
                D[r + c].append(nums[r][c])
        # print(D)
        res = []
        for _, arr in D.items():
            while arr:
                res.append(arr.pop())
        return res
