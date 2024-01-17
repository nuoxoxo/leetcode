class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        return [
            self.Solution_nested_loop,
        ][ random.randint(0,0) ]( phrases )

    # O( N*N )
    def Solution_nested_loop( self, phrases: List[str] ) -> List[str]:
        print('/nested_loop')
        L, R = defaultdict(list), defaultdict(list)
        res = set()
        for p in phrases:
            a = p.split()
            l, r = a[0], a[-1]
            if l in R: # if it is someone's tail
                for line in R[l]:
                    res.add( (line + ' ' + ' '.join(a[1:])).strip() )
            if r in L: # if it has been a head
                for line in L[r]:
                    res.add( (' '.join(a[:-1]) + ' ' + line).strip() )
            L[l].append(p)
            R[r].append(p)
        return sorted(list(res))
