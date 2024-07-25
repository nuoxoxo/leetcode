class Solution:
    def sortArray(self, arr: List[int]) -> List[int]:
        return [
            # Quicksort_using_randomness,
            Mergesort,
        ][0](arr)

def Mergesort(arr: List[int]) -> List[int]:
    def mergesort(L, R):
        if L == R:
            return [arr[L]]
        if L > R:
            return []
        M = (L + R) // 2

        Larr = mergesort(L, M)
        Rarr = mergesort(M + 1, R)

        res = []
        l, r = 0, 0
        NL = len(Larr)
        NR = len(Rarr)

        while l < NL and r < NR:
            if Larr[l] < Rarr[r]:
                res.append(Larr[l])
                l += 1
            else:
                res.append(Rarr[r])
                r += 1
        while l < NL:
            res.append(Larr[l])
            l += 1
        while r < NR:
            res.append(Rarr[r])
            r += 1
        return res
    N = len(arr)
    return mergesort(0, N - 1)


def Quicksort_using_randomness(arr: List[int]) -> List[int]:
    def quicksort(L, R):
        if L >= R:
            return
        l = L
        r = R
        piv = random.randint(L, R)
        val = arr[piv]
        while l <= r:
            while arr[l] < val:
                l += 1
            while arr[r] > val:
                r -= 1
            if l <= r:
                arr[l], arr[r] = arr[r], arr[l]
                l += 1
                r -= 1
        quicksort(L, r)
        quicksort(l, R)
    N = len(arr)
    quicksort(0, N - 1)
    return arr
