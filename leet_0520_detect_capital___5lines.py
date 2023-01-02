class Solution:
    def detectCapitalUse(self, s: str) -> bool:
        if s.lower() == s or s.upper() == s:
            return True
        if s[0].lower() != s[0] and s[1:].lower() == s[1:]:
            return True
        return False
