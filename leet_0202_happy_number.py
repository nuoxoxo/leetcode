class Solution:
    def isHappy(self, n: int) -> bool:

        return [
            self.Solution_Set, 
            self.Solution_Tortoise_and_Hare,
            self.Solution_Number_Theory
        ][ random.randint(0, 2) ]( n )

    # special solution : using Happ Number theory

    def Solution_Number_Theory(self, n: int) -> int:
        print('/theory: all cycles end at 4')
        while n != 1:
            n = sum([int(i) ** 2 for i in str(n)])
            if n == 4:
                return False
        return True

    # Solution 1 : set

    def Solution_Set(self, n: int) -> int:
        print('/set')
        Set = set()
        while n != 1:
            n = sum([int(i) ** 2 for i in str(n)])
            if n in Set:
                return False
            Set.add(n)
        return True

    # Solution 2 : Floyd's cycle detection - Tortoise & Hare

    def Solution_Tortoise_and_Hare (self, n: int) -> int:
        print('/floyd')
        def processing (n: int) -> int:
            return sum([int(i) ** 2 for i in str(n)])
        fast = n
        slow = n
        while fast != 1:
            fast = processing( processing(fast) )
            slow = processing( slow )
            if fast == slow:
                break
        return fast == 1

