class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        return [
            Sorting_by_occurences_Not_greedy,
        ][ 0 ]( arr )

    def Sorting_by_occurences_Not_greedy(self, arr: List[int], k: int) -> int:
        res = 0
        counter = dict(sorted(dict(Counter(arr)).items(), key=lambda x: x[1], reverse=True))
        A = []
        for key, v in counter.items():
            for _ in range(v):
                A.append(key)
        while k > 0:
            A.pop()
            k -= 1
        return len(set(A))
