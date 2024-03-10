class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return [
            # self.Set_intersection,
            self.Set_difference,
            # self.Two_pointers,

        ][ 0 ]( nums1, nums2 )

    def Two_pointers(self, n1: List[int], n2: List[int]) -> List[int]:
        n1.sort()
        n2.sort()
        L, R = len(n1), len(n2)
        res = []
        l, r = 0, 0
        while l < L and r < R:
            if n1[l] < n2[r]:
                l += 1
                continue
            elif n1[l] > n2[r]:
                r += 1
                continue
            elif not res or res[-1] != n1[l]:
                res.append(n1[l])
            l += 1
            r += 1
        return res

    def Set_difference(self, n1: List[int], n2: List[int]) -> List[int]:
        L, R = set(n1), set(n2)
        return list(L - (L - R))

    def Set_intersection(self, n1: List[int], n2: List[int]) -> List[int]:
        return set(n1) & set(n2)
