class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.md = medium
        self.sm = small
        self.bg = big

    def addCar(self, ct: int) -> bool:
        if (ct==1 and self.bg==0) or (ct==2 and self.md==0) or (ct==3 and self.sm==0):
            return False
        if (ct == 1):
            self.bg -= 1
        if (ct == 2):
            self.md -= 1
        if (ct == 3):
            self.sm -= 1
        return True

# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
