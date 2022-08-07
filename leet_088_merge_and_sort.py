class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        k = m + n - 1
        m -= 1
        n -= 1
        while m > -1 and n > -1:
            if nums1[m] > nums2[n]:
                nums1[k] = nums1[m]
                k -= 1
                m -= 1
            else:
                nums1[k] = nums2[n]
                k -= 1
                n -= 1
        while m > -1:
            nums1[k] = nums1[m]
            k -= 1
            m -= 1
        while n > -1:
            nums1[k] = nums2[n]
            k -= 1
            n -= 1
