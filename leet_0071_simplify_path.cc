class Solution {
public:
    string simplifyPath(string path)
    {
        deque<string>   E ;
        stringstream    ss(path);
        string          tmp, res = "/";

        while (getline(ss, tmp, '/'))
        {
            if (tmp == "" || tmp == ".")
                continue;
            if (tmp == "..")
            {
                if (E.size())
                    E.pop_back();
                continue;
            }
            E.push_back(tmp);
        }
        while (E.size())
        {
            res += E[0];
            E.pop_front();
            if (E.size())
                res += '/' ;
        }
        return res;
    }
};
