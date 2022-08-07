class Solution:
    def sortArray(self, arr: List[int]) -> List[int]:
        def quicksort(arr, L, R):
            if (L >= R):
                return
            i = L
            j = R
            piv = random.randint(L, R)
            val = arr[piv]
            while i <= j:
                while arr[i] < val:
                    i += 1
                while arr[j] > val:
                    j -= 1
                if i <= j:
                    arr[i], arr[j] = arr[j], arr[i]
                    i += 1
                    j -= 1
            quicksort(arr, L, j)
            quicksort(arr, i, R)
        quicksort(arr, 0, len(arr) - 1)
        return arr
