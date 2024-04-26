class Solution {
public:
    int fib(int n) {
        vector<int(*)(int)> Solutions {
            Tabulation_int_array,
            Tabulation_vector,
            // Recurse, // TLE
        };
        return Solutions[0](n);
    }


    static int Recurse(int n) {

        if (n < 2)
            return n;
        return Recurse(n - 1) + Recurse(n - 2);
    }


    static int Tabulation_int_array(int n) {

        if (n < 2)
            return n;
        int tr[n + 1];
        tr[0] = 0;
        tr[1] = 1;
        int i = 1;
        while (++i < n + 1) {
            tr[i] = tr[i - 2] + tr[i - 1];
        }
        return tr[n];
    }


    static int Tabulation_vector(int n) {

        vector<int> tr {0, 1};
        int i = 1;
        while (++i < n + 1) {
            tr.push_back(tr[i - 2] + tr[i - 1]);
        }
        return tr[n];
    }
};
