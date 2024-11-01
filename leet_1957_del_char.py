class Solution:
    def makeFancyString(self, s: str) -> str:
        arr = []
        i = 0
        N = len(s)
        prev = None
        count = 1
        while i < N:
            if s[i] == prev:
                count += 1
            else:
                if prev:
                    arr.append(prev)
                    arr.append(count)
                prev = s[i]
                count = 1
            i += 1
        arr.append(prev)
        arr.append(count)
        res = ''
        for i in range(0, len(arr), 2):
            n = 2 if arr[i + 1] > 2 else arr[i + 1]
            res += arr[i] * n
        return res
