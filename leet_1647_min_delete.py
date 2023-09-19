class Solution:
    def minDeletions(self, s: str) -> int:
        count = [0] * 26
        res = 0
        for c in s:
            count[ ord(c) - ord('a') ] += 1
        # print(count)
        count.sort()
        i = 0
        while i < 25:
            if count[i] == 0 or count[i] != count[i + 1]:
                i += 1
                continue
            res += 1
            count[i] -= 1
            i = 0
        return res
