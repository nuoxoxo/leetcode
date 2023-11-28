class Solution:
    def numberOfWays(self, corridor: str) -> int:
        mod = int(1e9 + 7)
        putsep = 0 # can put a sep here : a sep placed represents a factor for all prev arrangements
        ss = 0 # seat count
        res = 1
        L = len(corridor)
        for seat in corridor:
            if seat == 'P':
                if ss > 0 and ss % 2 == 0:
                    putsep += 1
            elif seat == 'S':
                # either no seat has yet been seen then res is 0
                # or all seen arrangements should *= potential future arrangements
                res *= putsep + 1
                res %= mod
                # ?? modulo is strange
                # res *= ((putsep % mod + 1) % mod) # ??
                putsep = 0 # encounter w/ seat stops the count 
                ss += 1
        if ss < 1 or ss % 2 != 0:
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
