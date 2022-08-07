/**
 * @param {number} big
 * @param {number} medium
 * @param {number} small
 */
var ParkingSystem = function(big, medium, small) {
    this.b = big
    this.m = medium
    this.s = small
};

/** 
 * @param {number} carType
 * @return {boolean}
 */
ParkingSystem.prototype.addCar = function(t) {
    if ((t==1&&this.b==0)||(t==2&&this.m==0)||(t==3&&this.s==0))
        return false
    if (t==1)   --this.b
    if (t==2)   --this.m
    if (t==3)   --this.s
    return true
};

/** 
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new ParkingSystem(big, medium, small)
 * var param_1 = obj.addCar(carType)
 */
