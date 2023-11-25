class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        res = []
        size = len(nums)
        for i in range(len(l)):
            # end = min(r[i] + 1, size)
            # tmp = nums[l[i] : end]
            tmp = nums[l[i] : r[i] + 1]
            if len(tmp) < 3:
                res.append(True)
                continue
            tmp.sort()
            diff = tmp[1] - tmp[0]
            ok = True
            for j in range(1, len(tmp)):
                if tmp[j] - tmp[j - 1] != diff:
                    ok = False
                    break
            res.append(ok)
        return res

