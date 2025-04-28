class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        # assert sorted(arr) == arr

        # bruteforce
        seen_pair = set()
        A = set(arr)
        N = len(arr)
        res = 0
        for l in range(N - 1):
            for r in range(l + 1, N):
                size = 2
                c = arr[l] + arr[r]
                a,b = arr[l], arr[r]
                while c in A:
                    a, b = b, c
                    if (a,b) in seen_pair:
                        break
                    seen_pair.add((a,b))
                    size += 1
                    c = a + b
                if size > 2:
                    res = max(res, size)
        return res

