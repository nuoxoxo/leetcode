class Solution:
    def maxLength(self, arr: List[str]) -> int:
        return [
            self.Solution_DFS_length_only,
            self.Solution_DFS_space_heavy,
        ][ random.randint(0,0) ]( arr )

    def Solution_DFS_length_only(self, arr:List[str]) -> int:
        print('/Solution_DFS_length_only - O(2^n)')
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

    def Solution_DFS_space_heavy(self, arr:List[str]) -> int:
        print('/Solution_DFS_space_heavy - O(2^n)')
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
        for _ in S: print( {} if not _ else _)
        print('\n')
