class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        res = []
        m = len(l)
        for i in range(m):
            temp = nums[l[i]:r[i] + 1]
            print(temp)
            if len(temp) == 2:
                res.append(True)
                continue 
            temp.sort()
            diff = temp[1] - temp[0]
            j = 1
            found = False
            for j in range(2, len(temp)):
                if temp[j] - temp[j - 1]^ diff:
                    found = True
                    break
            if found == 0:
                res.append(True)
            else:
                res.append(False)
        return res
