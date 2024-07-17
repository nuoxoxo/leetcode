class Solution {
public:
    string countOfAtoms(string formula)
    {
        #define MSI map<string, int>
        int N = formula.length();
        deque< MSI > Q;
        Q.push_back( MSI() );
        int i = 0;
        while (i < N)
        {
            char c = formula[i];
            if (c == '(')
            {
                Q.push_back( MSI() );
                i++;
            }
            else if (c == ')')
            {
                MSI counter = Q.back();
                Q.pop_back();
                int L = i + 1;
                int R = i + 1;
                while (R < N && '0' <= formula[R] && formula[R] <= '9')
                    R++;
                int amt = 1;
                string sub = formula.substr(L, R - L);
                cout << sub << endl;
                if (sub != "")
                    amt = stoi(sub);
                // amt = max(amt, 1);
                assert ( ! Q.empty() );
                for (auto & [k, v] : counter)
                    Q.back()[k] += v * amt;
                i = R;
            }
            else if ( 'A' <= c && c <= 'Z' )
            {
                string key;
                key += c;
                int L = i + 1;
                int R = i + 1;
                while (R < N && 'a' <= formula[R] && formula[R] <= 'z')
                    R++;
                key += formula.substr(L, R - L);
                i = R;
                L = R;
                while (R < N && '0' <= formula[R] && formula[R] <= '9')
                    R++;
                int amt = 1;
                string sub = formula.substr(L, R - L);
                cout << sub << endl;
                if (sub != "")
                    amt = stoi(sub);
                // amt = max(amt, 1);
                Q.back()[key] += amt;
                i = R;
            }
            else
            {
                // cout << i<<' '<<formula[i]<<' ' <<formula<<endl;
                assert (false);
            }
        }
        MSI counter = Q.back();
        Q.pop_back();
        assert (Q.empty());
        string res;
        for (auto & [k, v] : counter)
        {
            res += k;
            if (v > 1)
                res += to_string( v );
        }
        return res;
    }
};
