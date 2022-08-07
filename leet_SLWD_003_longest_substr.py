class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        E = set()
        left = 0
        res = 0
        for right in range(len(s)):
            while s[right] in E:
                E.remove(s[left])
                left += 1
            E.add(s[right])
            res = max(right - left + 1, res)
        return res
