class Solution {
public:
    string convert(string s, int numRows)
    {
        vector<string>  arr(numRows);
        string          res;
        int             n, r, c, i;

        if (numRows < 2)
            return s;
        n = s.size();
        i = -1;
        r = 0;
        while (++i < n)
        {
            arr[r] += s[i];
            // cout << arr[r] << "\t r = " << r << endl; 
            c = i / (numRows - 1);
            if (c % 2)
                --r;
            else
                ++r;
        }
        // vsp(arr);
        for (string tmp : arr)
            res += tmp;
        return res;
    }

    void    vsp(vector<string> arr)
    {
        for (string tmp: arr)
            cout << tmp << ' ';
        cout << endl;
    }
};
