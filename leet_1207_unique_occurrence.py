class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        return [
            self.Solution_sorting,
            self.Solution_dict_values,
            self.Solution_oneliner\
        ][ random.randint(0,2) ]( arr )

    # sort & get occurrences w/o builtin counter
    def Solution_sorting(self, arr):
        print('/Solution_sorting')
        arr.sort() # O( nlogn )
        occ = [] # occurrence
        i, j = 0, None
        while i < len(arr):
            j = i + 1
            while j < len(arr) and arr[i] == arr[j]:
                j += 1
            occ.append(j - i)
            i = j
        occ.sort()
        for i in range(len(occ) - 1):
            if occ[i] == occ[i + 1]:
                return False
            i += 1
        return True 

    # get occurrences, check if each occurrence is unique
    def Solution_dict_values(self, arr):
        print('/Solution_dict_values')
        D = defaultdict(int)
        for n in arr: D[n] += 1
        return len(set(D.values())) == len(D.values())   

    # check if sizes of occurrence array == number of unique elements
    def Solution_oneliner(self, arr):
        print('/Solution_oneliner')
        return len(set(arr)) == len(set(Counter(arr).values()))

