class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        lc, rc = 0, 0 # lc, rc is lcount and rcount
        l, r = None, None
        res = []
        for n in nums:
            if l == n:
                lc += 1
            elif r == n:
                rc += 1
            elif lc == 0:
                lc = 1
                l = n
            elif rc == 0:
                rc = 1
                r = n
            else:
                rc -= 1
                lc -= 1
        lc, rc = 0, 0
        for n in nums:
            if n == l:
                lc += 1
            elif n == r:
                rc += 1
        # print(l, lc, r, rc)
        if lc > len(nums) // 3:
            res.append(l)
        if rc > len(nums) // 3:
            res.append(r)
        return res
        
        
