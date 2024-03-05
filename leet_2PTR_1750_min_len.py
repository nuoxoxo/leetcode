class Solution:
    def minimumLength(self, s: str) -> int:
        N = len(s)
        l, r = 0, N - 1
        while l < r:
            if s[l] == s[r]:
                c = s[l]
                while l <= r and s[l] == c:
                    l += 1
                while l <= r and s[r] == c:
                    r -= 1
            else:break
        # print(len(s[l:r+1]), s[l:r+1])
        return r - l + 1
