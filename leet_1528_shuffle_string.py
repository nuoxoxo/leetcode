class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ss = s
        for i in range(len(s)):
            p = indices[i]
            ss = ss[0 : p] + s[i] + ss[p + 1 : len(s)]
        return ss
