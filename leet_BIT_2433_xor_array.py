class Solution:
    def findArray(self, pref: List[int]) -> List[int]:
        i = len(pref) - 1
        while i > 0:
            pref[i] = pref[i] ^ pref[i - 1]
            i -= 1
        return pref
