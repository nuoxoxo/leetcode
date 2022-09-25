class Solution:
    def sumEvenAfterQueries(self, nums: List[int], q: List[List[int]]) -> List[int]:
        res = []
        tt = 0
        for n in nums:
            if n % 2 == 0:
                tt += n
        for i in range(len(q)):
            val, idx = q[i][0], q[i][1]
            before = nums[idx]
            nums[idx] += val
            if before % 2 == 0:
                if nums[idx] % 2 == 0:
                    tt += val
                else:
                    tt -= before
            elif before % 2 != 0 and nums[idx] % 2 == 0:
                tt += nums[idx]
            res.append(tt)
        return res
