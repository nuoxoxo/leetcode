class Solution:
    def maximumSwap(self, num: int) -> int:
        # my way ---> 2 passes
        ## find out where decreasing ends - the last index of the descent
        lastdrop = 0
        A = [int(_) for _ in str(num)]
        N = len(A)
        for i in range(1, N):
            if A[i - 1] < A[i]:
                break
            lastdrop = i
        if lastdrop == N - 1:
            return num
        L, R = -1, max(A[lastdrop:])
        l, r = None, None
        ## strategy on each sides
        #   left side : 2 conditions
        #       - smaller than right side's max 
        #       - biggest of left side  
        #   right side 
        #       - 1st occurence of the max of right side's max
        for i, n in enumerate(A):
            if i <= lastdrop and L < n < R:
                L = n
                l = i
                continue
            if R == n:
                r = i
        print('dropping/ends', lastdrop, l, r)
        A[l], A[r] = A[r], A[l]
        res = 0
        for a in A:
            res = res * 10 + a
        return res
"""
2736
9973
98368
99887511
115
1993
10909091
"""
