class Solution:
    def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        return [
            Bruteforce_every_possible_missing_pair,
        ][0](nums1, nums2)

def Bruteforce_every_possible_missing_pair(nums1: List[int], nums2: List[int]) -> int:
    res = 0
    nums1.sort()
    nums2.sort()
    # print('1/', nums1)
    # print('2/', nums2)
    def OK(L:List[int], R:List[int]) -> bool:
        #assert L R are sorted
        diff = L[0] - R[0]
        for l, r in zip(L, R):
            if l - r != diff:
                return False
        return True
    N = len(nums1)
    for i in range(N - 1):
        for j in range(i + 1, N):
            alt = nums1[:i] + nums1[i + 1 : j] + nums1[j + 1:]
            if OK(alt, nums2):
                return nums2[0] - alt[0] # alt[0] - nums2[0] # BUG
    assert False

