class Solution:
    def romanToInt(self, s: str) -> int:
        E = {}
        E['I'] = 1;
        E['V'] = 5;
        E['X'] = 10;
        E['L'] = 50;
        E['C'] = 100;
        E['D'] = 500;
        E['M'] = 1000;
        num = 0
        i = 0
        while i < len(s):
            if i < len(s) - 1 and E[ s[i] ] < E[ s[i + 1] ]:
                num += E[s[i + 1]] - E[ s[i] ] 
                i += 2
            else:
                num += E[s[i]]
                i += 1
        return num
