class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        # laws/
        #   a^a = 0
        #   a^0 = a
        # sim/
        # [a,b] [x,y,x] /nums1, nums2
        #   [ a^x,a^y,a^z,b^x,b^y,b^z ] /nums3
        #   [ a^x^a^y^a^z^b^x^b^y^b^z] /nums3 xored
        #       ^   ^   ^   ^   ^   ^ --> x^x^y^y^z^z = 0 bc. len1 is even
        #     ^   ^   ^ --> a^a^a AND also b^b^b --> a ^ b bc. len2 is odd
        x1, x2 = 0, 0
        n1, n2 = len(nums1), len(nums2)
        for n in nums1: x1 ^= n
        for n in nums2: x2 ^= n
        if n1 % 2 == 0 and n2 % 2 == 0:
            return 0
        if n1 % 2 == 0:
            return x1
        if n2 % 2 == 0:
            return x2
        return x1 ^ x2

