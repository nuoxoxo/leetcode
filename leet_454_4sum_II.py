class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        E = defaultdict(int)
        res = 0
        for x in nums1:
            for y in nums2:
                E[x + y] += 1
        for x in nums3:
            for y in nums4:
                res += E[-x - y]
        return res
                
