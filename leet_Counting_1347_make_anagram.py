class Solution:
    def minSteps(self, s: str, t: str) -> int:

        def Solution_oneliner(s, t):
            return sum([ _ for _ in (collections.Counter(s) - collections.Counter(t)).values() if _ > 0])

        def Solution_frequency(s, t):
            D = defaultdict(int)
            for i, c in enumerate(s):
                D[c] += 1
                D[t[i]] -= 1            
            return sum([_ for _ in D.values() if _ > 0])

        choice = random.randint(0, 1)
        print([ 'Solution_oneliner', 'Solution_frequency' ][ choice ])
        return [Solution_oneliner, Solution_frequency][ choice ](s, t)
