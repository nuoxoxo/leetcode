class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        return [
            # self.Extra_space,
            self.Cyclic_sort,
        ][0](nums)

    def Cyclic_sort(self, nums: List[int]) -> List[int]:
        res = []
        N = len(nums)
        i = 0
        while i < N:
            if nums[i] != i + 1 and nums[i] != nums[nums[i] - 1]:
                #   Srange : this does not work but the 2nd line does
                # nums[i], nums[nums[i] - 1] = nums[nums[i] - 1], nums[i]
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
            else:
                i += 1
        for i in range(N):
            if nums[i] != i + 1:
                res.append(nums[i])
        return res

    def Extra_space(self, nums: List[int]) -> List[int]:
        N = len(nums)
        D = [0] * N
        res = []
        for i, n in enumerate(nums):
            if D[n - 1] == 1:
                res.append(n)
            else:
                D[n - 1] += 1
        return res
