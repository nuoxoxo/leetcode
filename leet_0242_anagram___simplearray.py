class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) == len(t):
            E = [0] * 26
            a = ord('a')
            for i in range(len(s)):
                E[ord(s[i]) - a] += 1
                E[ord(t[i]) - a] -= 1
            for n in E:
                if n != 0:
                    return False
            return True
        return False
        
        
