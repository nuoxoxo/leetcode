class Solution:
    def minimumSteps(self, s: str) -> int:
        # cases
        #   "11000111"
        #   "01010001"
        res = 0
        tmp = 0
        for c in s:
            if c == '1':
                tmp += 1
            else:
                res += tmp
        return res 
        # initial soln
        """
        N = len(s)
        L, R = -1, -1
        for i in range(N - 1, -1, -1):
            if i > -1 and s[i] == '1': continue
            if i == 0: return 0
            if s[i] == '0':
                R = i
                break
        for i in range(N):
            if i < N and s[i] == '0': continue
            if i == N: return 0
            if s[i] == '1':
                L = i
                break
        sub = s[L : R + 1]
        print(L, R, sub)
        return sub.count('0') * sub.count('1')
        """
