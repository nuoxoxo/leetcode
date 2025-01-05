class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:        
        N = len(s)
        dif = [0] * (N + 1) # idea of prefix sum
        a = ord('a')
        for l,r,d in shifts:
            if d == 0: d = -1
            dif[l] += d
            dif[r + 1] -= d
        res = ''
        realshift = 0
        for i in range(N):
            realshift = (realshift + dif[i]) % 26
            asc = (ord(s[i]) - a + realshift) % 26 + a
            res += chr(asc)
        return res
        """ # TLE ---> list manip is slow
        a = ord('a')
        for l,r,d in shifts:
            sub = [_ for _ in s[l:r+1]]
            if d == 0: d = -1
            for i,c in enumerate(sub):
                sub[i] = chr(a + (ord(c) - a + d) % 26)
            s = s[:l] + ''.join(sub) + s[r+1:]
        """
        """ # also TLE --> TC. is Ns * Nshift still too slow 
        a = ord('a')
        S = [ord(_) for _ in s]
        for l,r,d in shifts:
            if d == 0: d = -1
            for i in range(l, r + 1):
                S[i] = (S[i] - a + d) % 26 + a
        return ''.join(chr(_) for _ in S)
        """

