class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int len = s.size();
        if (len < 10)
            return vector<string>();
        set<string> seen, r;
        int         i = -1;
        while (++i < len - 9)
        {
            string  temp = s.substr(i, 10);
            if (seen.find(temp) != seen.end())
                r.insert(temp);
            seen.insert(temp);
        }
        return vector<string>(r.begin(), r.end());
    }
};
