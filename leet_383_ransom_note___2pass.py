class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp = [0] * 26
        a = ord('a')
        for c in magazine:
            mp[ord(c) - a] += 1
        for c in ransomNote:
            i = ord(c) - a
            mp[i] -= 1
            if mp[i] < 0:
                return False
        return True
