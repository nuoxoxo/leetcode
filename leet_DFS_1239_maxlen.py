class Solution:
    def maxLength(self, arr: List[str]) -> int:
        return [
            self.Solution_DFS_using_str_fastest_nonlocal,
            self.Solution_DFS_using_str_fastest,
            self.Solution_DFS_using_set_space_heavy,
            self.Solution_DFS_using_set_length_fast,
        ][ random.randint(0,0) ]( arr )

    def Solution_DFS_using_str_fastest_nonlocal (self, arr:List[str]) -> int:
        print('/Solution_DFS_using_str_fastest/modifies only the nonlocal')
        res = 0
        def DFS(arr: List[str], formed_string: str, index: int) -> None:
            if len(set(formed_string)) != len(formed_string):
                return
            nonlocal res
            res = max(res, len(formed_string))
            for i in range(index, len(arr)):
                DFS( arr, formed_string + arr[i], i + 1 )
        DFS( arr, '', 0 )
        return res

    def Solution_DFS_using_str_fastest (self, arr:List[str]) -> int:
        print('/Solution_DFS_using_str_fastest/recursively return')
        def DFS(arr: List[str], formed_string: str, index: int) -> int:
            if len(set(formed_string)) != len(formed_string):
                return 0
            size = len(formed_string)
            for i in range(index, len(arr)):
                size = max( size, DFS(arr, formed_string + arr[i], i + 1 ))
            return size
        return DFS(arr, '', 0)

    def Solution_DFS_using_set_length_fast(self, arr:List[str]) -> int:
        print('/Solution_DFS_using_set_length_fast - O(2^n)')
        sets = [ set(s) for s in arr if len(set(s)) == len(s) ]
        N = len(sets)
        seen = set()
        res = 0
        def DFS(seen, index, END):
            if index == N:
                nonlocal res
                res = max(res, len(seen))
                return
            DFS( seen, index + 1, END )
            if seen.isdisjoint( sets[index] ):
                DFS( seen.union(sets[index]), index + 1, END)
        DFS(seen, 0, N)
        return res

    def Solution_DFS_using_set_space_heavy(self, arr:List[str]) -> int:
        print('/Solution_DFS_using_set_space_heavy - O(2^n)')
        sets = [ set(_) for _ in arr if len(set(_)) == len(_) ] # pre-filter
        self.DBG_setlist( sets )
        N = len(sets)
        seen = set()
        final_sets = []
        def DFS(seen, index, END):
            if index == END:
                final_sets.append(seen)
                return
            DFS( seen, index + 1, END)
            if seen.isdisjoint( sets [index] ):
                # DFS( index + 1, seen | sets [index], END)
                DFS( seen.union(sets[index]), index + 1, END )

        DFS (seen, 0, N)
        self.DBG_setlist( final_sets )
        return max([ len(_) for _ in final_sets ])

    # Just a helper

    def DBG_setlist(self, S: List[Set[str]]) -> None:
        print('/dgb')
        for _ in S: print({} if not _ else _)
        print('\n')
