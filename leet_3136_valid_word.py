class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        vow, con = False, False
        for c in word:
            if not c.isalnum():
                return False
            if c.lower() in 'aeiou':
                vow = True
            elif c.isalpha():
                con = True
        if all([vow, con]):
            return True
        # print([vow, con])
        return False
