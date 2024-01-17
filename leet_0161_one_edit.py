class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        return [ 
            self.Solution_skip_equal_prefix,
            self.Solution_skip_equal_prefix_alt\
        ][ random.randint(0,1) ]( s, t )

    def Solution_skip_equal_prefix_alt(self, s: str, t: str) -> bool:
        print('/Solution_skip_equal_prefix_alt')
        if s == t: return False
        i = 0
        while i < min(len(s), len(t)) and s[i]==t[i]:
            i += 1
        ls = lt = 1
        if len(s) < len(t):
            ls = 0
        elif len(t) < len(s):
            lt = 0
        return s[i + ls:] == t[i + lt:]

    def Solution_skip_equal_prefix(self, s: str, t: str) -> bool:
        print('/Solution_skip_equal_prefix')
        if s == t: return False
        i = 0
        while i < len(s) and i < len(t) and s[i]==t[i]:
            i += 1
        return True in [
            s[i:] == t[i+1:],
            s[i+1:] == t[i:],
            s[i+1:] == t[i+1:]]

