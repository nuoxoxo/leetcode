class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        r = []
        def backtrack(s, n, k):
            if len(s) == n:
                r.append(int(s))
                return
            if len(s) == 0:
                last = -1
            else:
                last = ord(s[-1]) - ord('0')
            for i in range(10):
                if last == -1 and i == 0:
                    continue
                if last == -1 or abs(last - i) == k:
                    s += chr(i + ord('0'))
                    backtrack(s, n, k)
                    s = s[:-1]
        backtrack('', n, k);
        return r
