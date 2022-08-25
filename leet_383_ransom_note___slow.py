class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        alpha = []
        for i in range(26):
            alpha.append(0)
        for c in ransomNote:
            alpha[ ord(c) - ord('a') ] += 1
        for c in magazine:
            alpha[ ord(c) - ord('a') ] -= 1
        for n in alpha:
            if n > 0:   return False
        return True
