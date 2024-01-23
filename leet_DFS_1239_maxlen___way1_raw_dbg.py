class Solution:
    def maxLength(self, arr: List[str]) -> int:
        sets = [ set(_) for _ in arr if len(set(_)) == len(_) ]
        self.DBG_setlist( sets )
        N = len(sets)
        seen = set()
        final_sets = []

        def DFS(index, seen, END):
            if index == N:
                final_sets.append(seen)
                return
            DFS( index + 1, seen, END)
            if seen.isdisjoint( sets [index] ):
                # DFS( index + 1, seen | sets [index], END)
                DFS( index + 1, seen.union(sets[index]), END )

        DFS (0, seen, N)

        self.DBG_setlist( final_sets )
        return max([ len(_) for _ in final_sets ])

    def DBG_setlist(self, S: List[Set[str]]) -> None:
        print('/dgb')
        for _ in S: print( {} if not _ else _)
        print('\n')
