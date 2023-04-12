class Solution {
public:
    string simplifyPath(string path) {
        deque<string>   D;
        string  res, word;
        int     i = -1;
        while (++i < (int) path.size())
        {
            if (path[i] == '/')
                continue ;
            word = "";
            while (i < (int) path.size() && path[i] != '/')
                word += path[i++];
            if (word == ".")
                continue ;
            if (word == "..")
            {
                if (!D.empty())
                    D.pop_back();
            }
            else
                D.push_back(word);
        }
        while ( !D.empty())
        {
            string tmp = "/" + D.back();;
            res = tmp + res;
            D.pop_back();
        }
        return res == "" ? "/" : res;
    }
};
