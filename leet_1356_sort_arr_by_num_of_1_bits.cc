class Solution {
public:
    vector<int> sortByBits(vector<int>& arr)
    {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            int n1 = counter(a);
            int n2 = counter(b);
            if (n1 == n2)
                return a < b;
            return n1 < n2;
        });
        return arr;
    }

    int counter(int a)
    {
        int res = 0;
        while (a)
        {
            res += a & 1;
            a >>= 1;
        }
        return res ;
    }
};
