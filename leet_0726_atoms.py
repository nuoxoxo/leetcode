class Solution:
    def countOfAtoms(self, formula: str) -> str:
        """
        "K4(ON(SO3)2)2"

        deque([Counter()])
        deque([Counter(), Counter()])
        deque([Counter(), Counter(), Counter()])
        """
        N = len(formula)
        Q = deque()
        Q.append( defaultdict(int) )
        i = 0
        while i < N:
            char = formula[i]
            if char == '(':
                i += 1
                Q.append( defaultdict(int) )
            elif char == ')':
                counter = Q.pop()
                L = i + 1
                R = i + 1
                while R < N and formula[R].isdigit():
                    R += 1
                # 2. find how many 'amt' we need
                amt = 1
                if formula[L : R]:
                    amt = max(int( formula[L : R] ), 1)
                assert Q
                for key, prev in counter.items():
                    Q[-1][key] += amt * prev
                i = R
            elif char.isalpha() and char.isupper():
                # 1. parse atom name
                key = char
                L = i + 1
                R = i + 1
                while R < N and formula[R].islower():
                    R += 1
                key += formula[L : R]
                i = R
                L = R
                while R < N and formula[R].isdigit():
                    R += 1
                amt = 1
                if formula[L : R]:
                    amt = max(int( formula[L : R] ), 1)
                assert Q
                Q[-1][key] += amt
                i = R
            else:
                assert False
        counter = Q.pop()
        assert not Q
        counter = dict(sorted(counter.items()))
        res = ''
        for key, amt in counter.items():
            res += key
            if amt > 1:
                res += str(amt)
        return res
