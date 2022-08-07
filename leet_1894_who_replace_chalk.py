class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        t = 0
        for c in chalk:
            t += c
        k %= t
        i = 0
        n = len(chalk)
        while True:
            if k < chalk[i]:
                return i
            k -= chalk[i]
            i = (i + 1) % n
        return -1
