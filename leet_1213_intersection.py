class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        choice = random.randint(0, 1)
        return [
            self.Solution_oneliner, 
            self.Solution_intersect,
            self.Solution_frequency\
        ][ 2 ](arr1, arr2, arr3)

    # Fastest : frequency table

    def Solution_frequency (self, arr1, arr2, arr3):
        print('/frequency table')
        D = Counter(arr1+arr2+arr3)
        res = []
        for n, f in D.items():
            if f == 3:
                res.append(n)
        return res 
       
    def Solution_oneliner (self, arr1, arr2, arr3):
        print('/oneliner')
        return sorted(list(set(arr1) & set(arr2) & set(arr3)))

    def Solution_intersect (self, arr1, arr2, arr3):
        print('/intersect')
        S = set(arr1) & set(arr2) & set(arr3)
        res = []
        for n in arr1+arr2+arr3:
            if n in S:
                S.discard(n)
                res.append(n)
        return res

