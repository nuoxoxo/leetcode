class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 0 or len(s) == 1:
            return False
        S = []
        E = {'}': '{', ')': '(', ']': '['}
        for c in s:
            if c in E.values():
                S.append(c)
            elif not S or S.pop() != E[c]:
                    return False
        if not S:
            return True
        return False
