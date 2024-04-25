class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        lens = [0] * 26
        for i, c in enumerate(s):
            idx = ord(c) - ord('a')
            Loffset = max(0, idx - k)
            Roffset = min(idx + k + 1, 26)
            sub = lens[Loffset:Roffset]
            lens[idx] = max(sub) + 1
        return max(lens)
