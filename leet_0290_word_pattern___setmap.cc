class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        map<char, string>   D;
        vector<string>  a;
        set<string>     set1;
        set<char>       set2;
        string          tmp;
        stringstream    ss(s);

        while (ss >> tmp)
            a.push_back(tmp);
        if (pattern.length() ^ a.size())
            return false;
        for (string t: a)
            set1.insert(t);
        for (char c: pattern)
            set2.insert(c);    
        if (set1.size() ^ set2.size())
            return false;
        int i = -1;
        while (++i < a.size())
        {
            if (D.find(pattern[i]) == D.end())
                D[pattern[i]] = a[i];
            else
            {
                if (D[pattern[i]] == a[i])
                    continue ;
                return false;
            }
        }
        return true;
    }
};
