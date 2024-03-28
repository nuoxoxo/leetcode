class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        return [
            self.BruteForce,
        ][0](s, k)

    def BruteForce(self, s: str, k: int) -> int:
        res = 0
        end = min(len(s), 26)
        for uniques in range(1, end + 1): #[1, 26]
            D = defaultdict(int)
            l = 0
            for r, c in enumerate(s):
                D[c] += 1
                while len(D) > uniques:
                    D[s[l]] -= 1
                    if D[s[l]] == 0:
                        del D[s[l]]
                    l += 1
                # print(uniques, [(_, v) for _, v in D.items()])
                # checking it D.items all are above k
                if all (v >= k for _, v in D.items()):
                    res = max(res, r - l + 1)
        return res

