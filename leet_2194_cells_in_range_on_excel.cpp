class Solution {
public:
    vector<string> cellsInRange(string s)
    {
        vector<string>  res;
        stringstream    ss(s);
        char            c1, c2;
        int             n1, n2;

        ss >> c1 >> n1 >> c2 >> c2 >> n2;
        while (c1 < c2 + 1)
        {
            int i = n1;
            while (i < n2 + 1)
            {
                string  temp;
                temp += c1;
                temp += i + 48;
                res.push_back(temp);
                ++i;
            }
            ++c1;
        }
        return res ;
    }
};
