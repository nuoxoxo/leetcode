class Solution:
    def detectCapitalUse(self, s: str) -> bool:
        if len(s) == 1:
            return True
        c = s[0]
        if c.islower():
            for i in range(1, len(s)):
                if s[i].isupper():
                    return False
        else:
            c = s[1]
            if c.islower():
                for i in range(2, len(s)):
                    if s[i].isupper():
                        return False
            elif c.isupper():
                print(s)
                for i in range(2, len(s)):
                    if s[i].islower():
                        return False
        return True
