class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        st = set()
        for i in range(len(s) + 1 - k):
            st.add(s[i : i + k])
        return len(st) == 2 ** k

# same code, above is faster

"""
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = len(s)
        if n < k:
            return False
        st = set()
        for i in range(n - k + 1):
            st.add(s[i : i + k])
        if len(st) == 2 ** k:
            return True
        return False
"""
