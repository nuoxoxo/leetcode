class Solution:
    def numberOfWays(self, corridor: str) -> int:
        mod = int(1e9 + 7)
        pls = 0 # a sep placed represents a factor for all prev arrangements
        sea = 0 # seat count
        res = 1
        L = len(corridor)
        for c in corridor:
            if c == 'P':
                if sea > 0 and sea % 2 == 0:
                    pls += 1
            elif c == 'S':
                # either no seat has yet been seen then res is 0
                # or all seen arrangements should *= potential future arrangements
                res *= pls + 1
                res %= mod
                # ?? modulo is strange
                # res *= ((putsep % mod + 1) % mod) # ??
                pls = 0 # encounter w/ seat stops the count 
                sea += 1
        if sea < 1 or sea % 2 != 0:
            return 0
        return res
"""
SSPPSPS
SS | PPSPS
SSPP | SPS
SSP | PSPS

SSPPSPSPS
SS | PPSPSPS ---> x
SSPPS | PSPS ---> x
SSPPSP | SPS ---> x
"""
