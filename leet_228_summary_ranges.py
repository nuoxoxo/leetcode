class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        o = ord('0')
        E = []
        i = 0
        while i < n:
            boo = False
            j = i
            while j < n - 1:
                if nums[j] == nums[j + 1] - 1:
                    if not boo:
                        boo = True
                    j += 1
                else:
                    break
            if not boo:
                E.append(str(nums[j]))
            else:
                E.append(str(nums[i]) + "->" + str(nums[j]))
            i = j + 1
        return E
