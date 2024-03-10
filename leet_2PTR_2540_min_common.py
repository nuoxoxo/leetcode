class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        return [
            self.Two_pointers,
            # self.Binary_search,
            # self.Set_x1,
            # self.Set_x2,
        ][ 0 ]( nums1, nums2 )

    def Two_pointers(self, nums1: List[int], nums2: List[int]) -> int:
        i, j = 0, 0
        len1, len2 = len(nums1), len(nums2)
        while i < len1 and j < len2:
            if nums1[i] == nums2[j]:
                return nums1[i]
            if nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return -1

    def Binary_search(self, nums1: List[int], nums2: List[int]) -> int:
        N = len(nums2)
        for n in nums1:
            L = 0
            R = N - 1
            while L <= R:
                mid = (L + R) // 2
                if n == nums2[mid]:
                    return n
                if n < nums2[mid]:
                    R = mid - 1
                else:
                    L = mid + 1
        return -1

    def Set_x1(self, nums1: List[int], nums2: List[int]) -> int:
        s = set(nums1)
        for n in nums2:
            if n in s:
                return n
        return -1

    def Set_x2(self, nums1: List[int], nums2: List[int]) -> int:
        l = list(set(nums1) & set(nums2))
        return -1 if not l else min(l)
