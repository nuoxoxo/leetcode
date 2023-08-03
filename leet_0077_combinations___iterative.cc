class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> comb(k, 0);
        int i = 0;
        while (i > -1)
        {
            comb[i] += 1;
            if (comb[i] > n)
            {
                i--;
                cout << "U : i - 1 = " << i << endl;
            }
            else if (i == k - 1)
            {
                res.push_back(comb);
                cout << "M : ";
                printer(comb);
            }
            else
            {
                cout << "D(1) : ";
                printer(comb);
                i++;
                comb[i] = comb[i - 1];
                cout << "D(2) : ";
                printer(comb);
            }
        }
        return res;
    }

    void    printer(vector<int> comb)
    {
        for (int n: comb)
        {
            cout << n << ' ';
        }
        cout << endl;
    }
};
