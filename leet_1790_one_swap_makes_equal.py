class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        s = len(s1)
        tmp1 = ""
        tmp2 = ""
        i = 0
        n = 0
        while i < s:
            if s1[i] != s2[i]:
                tmp1 += s1[i]
                tmp2 += s2[i]
                n += 1
            if n > 2:
                return False
            i += 1
        if n != 2:
            return False
        tmp1 = "".join(sorted(tmp1))
        tmp2 = "".join(sorted(tmp2))
        if tmp2 == tmp1:
            return True
        return False
