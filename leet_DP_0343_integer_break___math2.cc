class Solution {
public:
    /*
    if n < 4:
        return n - 1
    quo = n // 3
    rem = n % 3
    if rem == 2:
        return 3 ** quo * 2
    if rem == 1:
        return 3 ** (quo - 1) * 4
    return 3 ** quo 
    */
    int integerBreak(int n)
    {
        if (n < 4)
            return n - 1;
        int quo = n / 3;
        int rem = n % 3;
        if (rem == 2)
            return pow(3, quo) * 2;
        if (rem == 1)
            return pow(3, quo - 1) * 4;
        return pow(3, quo);
        
    }
};
