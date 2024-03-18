class Solution:
    def minTimeToType(self, word: str) -> int:
        res = len(word)
        for i, char in enumerate(word):
            if i == 0:
                dist = ord(word[0]) - ord('a')
            else:
                dist = abs(ord(char) - ord(word[i - 1]))
            res += min(26 - dist, dist)
        return res
