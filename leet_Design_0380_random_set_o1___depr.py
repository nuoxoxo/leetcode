class RandomizedSet:

    def __init__(self):
        self.mp = {}
        self.a = []

    def insert(self, val: int) -> bool:
        
        if val in self.mp:
            return False
        self.a.append(val)
        self.mp[val] = len(self.a) - 1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.mp:
            return False

        """
        Get index of val in map
        """

        i = self.mp[val]

        """
        Replace the item at this index with the last item in the value array
        """

        self.a[i] = self.a[-1]
        # self.a.pop()  ### Buggy line

        """
        Update the replacement's index in map as well
        """

        replmt = self.a[i]
        self.mp[replmt] = i
        self.mp.pop(val)
        self.a.pop()
        return True
    
    def getRandom(self) -> int:
        # return self.a[random.randint(0, 1e9) % len(self.a)]
        return random.choice(self.a)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
