
/*

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return (n > 0 && !(n & (n - 1)));
    }
};

*/

//  above: crazy bit manipulation
//  below: OT(1) solve, hacked on prompt constraint


class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (!n)                         return (false);
        if (n > 0 && !(1073741824 % n)) return (true);
        return (false);
    }
};

