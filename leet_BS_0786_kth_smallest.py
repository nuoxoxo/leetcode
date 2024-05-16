class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:

        # Binary search - basically brute forced but it should be the best

        N = len(arr)
        L = 0
        R = 1.0
        while L < R:
            maxf = 0.0
            mid = (L + R) / 2
            I = None
            J = None # as in res -> [I, J]
            j = 1
            Kth = 0
            for i in range(N - 1):
                while j < N and arr[i] > arr[j] * mid:
                # count all denominators (A[j]) that give A[i]/A[j] > mid
                    j += 1
                # there J n's that give A[i]/A[j] > mid
                # hence N-J n's give A[i]/A[j] <= mid
                Kth += N - j
                if j == N:
                    break
                # upd. Max fraction which is < Mid
                if maxf < arr[i] / arr[j]:
                    I = arr[i]
                    J = arr[j]
                    maxf = arr[i] / arr[j]
            if Kth == k:
                return [I, J]
            if Kth > k:
                R = mid
            else:
                L = mid
        return []
