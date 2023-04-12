class Solution {
public:
    string simplifyPath(string path) {
        deque<string>   D;
        stringstream    ss(path);
        string          res, word;
        while (getline(ss, word, '/'))
        {
            if (word == "." || word == "")
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
