class Solution:
    def addStrings(self, s1: str, s2: str) -> str:
        len1 = len(s1)
        len2 = len(s2)
        diff = abs(len1 - len2)
        size = max(len1, len2)
        z = ord('0')
        v = []
        s = ""
        if len1 < len2:
            s1 = s1.zfill(size)
        else:
            s2 = s2.zfill(size)
        for i in range(size - 1, -1, -1):
            v.append(ord(s1[i]) + ord(s2[i]) - 2 * z)
        for i in range(size):
            if v[i] > 9:
                carry = v[i] // 10
                if i < size - 1:
                    v[i + 1] += carry
                else:
                    v.append(carry)
                v[i] %= 10
        for n in v:
            s += chr(n + z)
        return s[::-1]
