class Solution:
    def knightDialer(self, n: int) -> int:
        mod = int(1e9 + 7)
        s = [1] * 10 # state
        for i in range(n - 1):
            ns = [0] * 10 # new state
            ns[1] = (s[6] + s[8]) % mod 
            ns[2] = (s[7] + s[9]) % mod 
            ns[3] = (s[4] + s[8]) % mod 
            ns[4] = (s[3] + s[9] + s[0]) % mod 
            # ns[5] = 
            ns[6] = (s[1] + s[7] + s[0]) % mod 
            ns[7] = (s[2] + s[6]) % mod 
            ns[8] = (s[1] + s[3]) % mod 
            ns[9] = (s[2] + s[4]) % mod 
            ns[0] = (s[4] + s[6]) % mod 
            s = ns
        return sum(s) % mod 
"""
1 - 6 8
2 - 7 9 
3 - 4 8
4 - 3 9 0
5 - none
6 - 1 7 0
7 - 2 6 
8 - 1 3
9 - 2 4
0 - 4 6
"""
