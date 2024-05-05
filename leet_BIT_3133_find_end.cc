class Solution {
public:
    long long minEnd(int n, int x)
    {

        vector<char> N;
        vector<char> Xreversed;

        n -= 1;
        auto n_bitset = std::bitset<sizeof(int) * 8>(n);
        string n_binstring = n_bitset.to_string();
        for (char c: n_binstring)
            N.push_back( c );

        auto x_bitset = std::bitset<sizeof(int) * 8>(x);
        string x_binstring = x_bitset.to_string();
        for (char c: x_binstring)
            Xreversed.push_back( c );
        reverse(begin(Xreversed), end(Xreversed));

        vector<char> arr;
        for (char c: Xreversed)
        {
            if (c == '0')
            {
                if ( ! N.empty())
                {
                    arr.push_back(N.back());
                    N.pop_back();
                }
                else
                {
                    arr.push_back('0');
                }
            }
            else
            {
                arr.push_back('1');
            }
        }
        while (!N.empty())
        {
            arr.push_back(N.back());
            N.pop_back();
        }
        reverse(begin(arr), end(arr));
        string temp(begin(arr), end(arr));
        long long res = stoll(temp.c_str(), nullptr, 2);
        return res;
    }
};
