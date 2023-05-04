class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        r, d = [], []
        i = 0
        while i < len(senate):
            c = senate[i]
            if c is 'R':
                r.append(i)
            else:
                d.append(i)
            i += 1
        while r and d :
            rr = r.pop(0)
            dd = d.pop(0)
            if rr < dd:
                r.append(i)
                # i += 1
            else:
                d.append(i)
            i += 1
        if r:
            return 'Radiant'
        return 'Dire'
