class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        # new soln

        i = m - 1
        j = n - 1
        R = m + n - 1
        while i > -1 and j > -1:
            a = nums1[i]
            b = nums2[j]
            if a >= b:
                nums1[R] = a
                i -= 1
            else:
                nums1[R] = b
                j -= 1
            R -= 1
        while j > -1:
            nums1[R] = nums2[j]
            j -= 1
            R -= 1

        # old soln
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
        """
