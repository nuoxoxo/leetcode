class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        return [
            # Frequency_map,
            Index_map,
        ][0](arr1, arr2)

def Index_map(arr1: List[int], arr2: List[int]) -> List[int]:
    D = defaultdict(int)
    for i, n in enumerate(arr2):
        D[n] = i
    def cmpfunc(l, r) -> int:
        if l in D and r in D:
            return -1 if D[l] < D[r] else 1
        elif l in D: return -1
        elif r in D: return 1
        return -1 if l < r else 1 if l > r else 0
    return sorted(arr1, key=cmp_to_key(cmpfunc))

def Frequency_map(arr1: List[int], arr2: List[int]) -> List[int]:
    D = defaultdict(int)
    tail = []
    res = []
    for n in arr1:
        if n not in arr2:
            tail.append(n)
        else:
            D[n] += 1
    tail.sort()
    for n in arr2:
        res += [n] * D[n]
    return res + tail
