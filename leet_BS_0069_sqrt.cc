class Solution {
public:
    int mySqrt(int x) {
        vector<int(*)(int)> Solutions {
            Solution_Binary_Search,
            Solution_Newton,
            Solution_Brute_Force,
        };
        return Solutions[ std::rand() % Solutions.size() ]( x );
    }
    // Binary search
    static int Solution_Binary_Search (int x) {
        cout << "/Solution_Binary_Search\n";
        if (x == 0 || x == 1) return x;
        long long L = 0, R = x / 2, res = 1;
        while (L <= R)
        {
            long long mid = (R-L)/2 + L;
            long long sq = mid * mid;
            if (sq == x) return mid;
            if (sq > x) {
                R = mid - 1;
            } else {
                res = mid;
                L = mid + 1;
            }
        }
        return res;
    }
    // Newton's solution
    static int Solution_Newton (int x) {
        cout << "/Solution_Newton\n";
        if (x == 0 || x == 1) return x;
        long long res = x;
        while (res * res > x) {
            res = (res + x / res) / 2; // Newton's formula
        }
        return res;
    }
    // Brute force
    static int Solution_Brute_Force (int x) {
        cout << "/Solution_Brute_Force\n";
        if (x == 0 || x == 1) return x;
        long long res = 1;
        while (res * res <= x && (res+1) * (res+1) <= x)
            ++res;
        return res;
    }
};
