class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        s = set()
        for n in nums1:
            if n in nums2 or n in nums3:
                s.add(n)
        for n in nums2:
            if n in nums3:
                s.add(n)
        return list(s)
