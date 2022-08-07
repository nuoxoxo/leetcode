class ParkingSystem {
private:
    int B, M, S;
public:
    ParkingSystem(int big, int medium, int small)
    {
        B = big;
        S = small;
        M = medium;
    }
    
    bool addCar(int type)
    {
        if ((type == 1 && !B) || (type == 2 && !M) || (type == 3 && !S))
            return false ;
        if (type == 1)  --B;
        if (type == 2)  --M;
        if (type == 3)  --S;
        return true ;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
