class ParkingSystem {
public:
    vector<int> p;
    ParkingSystem(int big, int medium, int small)
    {
        p = {big, medium, small} ;
    }
    
    bool addCar(int carType)
    {
        if (p[carType - 1] < 1) return false ;
        --p[carType - 1] ;
        return true ;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
