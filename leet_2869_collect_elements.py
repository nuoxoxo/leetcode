class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        check = []
        res = 0
        for n in range(1, k + 1):
            check.append(n)
        while check:
            n = nums.pop()
            if n in check:
                check.remove(n)
            # print(check)
            res += 1
        return res
