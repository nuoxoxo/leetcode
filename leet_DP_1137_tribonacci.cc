class Solution {
public:
    int tribonacci(int n) {

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
        if (n == 2)
            return 1;
        return Recurse(n - 1) + Recurse(n - 2) + Recurse(n - 3);
    }


    static int Tabulation_int_array(int n) {

        if (!n)
            return n;
        if (n < 3)
            return 1;
        int tr[n + 1];
        tr[0] = 0;
        tr[1] = tr[2] = 1;
        int i = 2;
        while (++i < n + 1) {
            tr[i] = tr[i - 3] + tr[i - 2] + tr[i - 1];
        }
        return tr[n];
    }


    static int Tabulation_vector(int n) {

        vector<int> tr {0, 1, 1};
        int i = 2;
        while (++i < n + 1) {
            tr.push_back(tr[i - 3] + tr[i - 2] + tr[i - 1]);
        }
        return tr[n];
    }
};
