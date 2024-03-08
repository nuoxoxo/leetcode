class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        D = dict(sorted(Counter(nums).items(), key=lambda x:x[1], reverse=True))
        top = list(D.items())[0][1]
        res = 0
        for v in D.values():
            if v != top:
                break
            res += top
        return res
