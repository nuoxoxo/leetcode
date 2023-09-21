class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        N = sorted(nums1 + nums2)
        L = len(N)
        if L % 2 == 1:
            return N[L // 2]
        return (N[L // 2 - 1] + N[L // 2 ]) / 2

