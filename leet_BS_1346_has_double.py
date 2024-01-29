class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        return [
            # self.Solution_binary_search,
            self.Solution_On2_even_odd,
            # self.Solution_prod_2_array,
            # self.Solution_Counter,
        ][ random.randint(0,0) ]( arr )


    def Solution_On2_even_odd(self, arr):
        print('/Solution_On2_even_odd')
        for i in range(len(arr)):
            n = arr[i]
            if n % 2 == 0:
                if n // 2 in arr[i + 1:] or n * 2 in arr[i + 1:]:
                    return True
            elif n * 2 in arr[i + 1:]:
                return True
        return False


    def Solution_binary_search(self, arr):
        print('/Solution_binary_search')
        arr.sort()
        for idx in range(len(arr)):
            prod = 2 * arr[idx]
            l, r = 0, len(arr) - 1
            while l <= r:
                mid = (r - l) // 2 + l
                m = arr[mid]
                if m == prod and mid != idx:
                    return True
                if m > prod:
                    r = mid - 1
                else:
                    l = mid + 1
        return False
            

    def Solution_Counter(self, arr):
        print('/Solution_Counter')
        if arr.count(0) > 1:
            return True
        D = {}
        for _ in arr: D[_*2] = _
        for n in arr:
            if n in D and n != 2*n :
                return True
        return False

    def Solution_prod_2_array(self, arr):
        print('/Solution_prod_2_array')
        if arr.count(0) > 1:
            return True
        prod = [_*2 for _ in arr if _ != 0]
        return any([_ in prod for _ in arr])
