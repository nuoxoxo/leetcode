class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        return [
            # self.nSquare,
            # self.using_bisect_left,   # faster than Nsquare
            self.binary_search,         # fastest
        ][0](nums)

    def binary_search(self, nums: List[int]) -> int:
        lens = []
        for n in nums:
            N = len(lens)
            if not lens or lens[-1] < n:
                lens.append(n)
            else:
                L = 0
                R = N - 1
                while L < R:
                    mid = (R - L) // 2 + L
                    if lens[mid] < n:
                        L = mid + 1
                    else:
                        R = mid
                lens[R] = n
        return len(lens)

    def using_bisect_left(self, nums: List[int]) -> int:
        lens = []
        for n in nums:
            i = bisect.bisect_left(lens, n)
            if i == len(lens):
                lens.append(n)
            else:
                lens[i] = n
        return len(lens)

    def nSquare(self, nums: List[int]) -> int:
        N = len(nums)
        INF = 10 ** 20
        lens = [INF] * (N + 1)
        lens[0] = -INF
        for n in nums:
            for i in range(0, N + 1):
                if lens[i] < n:
                    if lens[i + 1] > n:
                        lens[i + 1] = n
            # print(n)
            # print(lens)
        res = -1
        for i in range(N, -1, -1):
            if lens[i] != INF:
                res = i
                break
        # print(lens)
        return res

