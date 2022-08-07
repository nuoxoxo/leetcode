class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), 
             [&](int& a, int& b) {
                 int x = countOnebits(a), y = countOnebits(b);
                 if (x == y) return a < b;
                 return x < y ;
             }
        );
        return arr ;
    }

    int countOnebits(int n)
    {
        int c = 0 ;

        while (n)
        {
            c += n & 1;
            n = n >> 1;
        }
        return c ;
    }
};
