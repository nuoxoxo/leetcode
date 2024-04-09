class Solution:
    def checkValidString(self, s: str) -> bool:
        L = [] # left pareathesis
        A = [] # astrisks
        for i, c in enumerate(s):
            if c == '(':
                L.append(i)
            elif c == ')':
                if L:
                    L.pop()
                elif A:
                    A.pop()
                else:
                    return False
            elif c == '*':
                A.append(i)
        # final check:
        #   a ( must be left of an *
        while L and A:
            if L[-1] < A[-1]:
                L.pop()
                A.pop()
            else:
                return False
        if L:
            return False
        return True

