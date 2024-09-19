class Solution {
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<vector<int>(*)(string)> Solutions {
            Using_catalan_number,
        };
        return Solutions[0](expression);
    }

    static vector<int> Using_catalan_number(string expression)
    {
        // Step - tokenize
        vector<string> tokens;
        string num = "";
        for (char c : expression)
        {
            if ('0' <= c && c <= '9')
                num += c;
            else
            {
                if (num != "")
                {
                    tokens.push_back(num);
                    num = "";
                }
                tokens.push_back(string(1, c));
            }
        }
        if (num != "")
            tokens.push_back(num);

        // Step - std::function f()
        std::function<vector<int>(int, int)> f = [&](int L, int R){
            if (L == R)
                return vector<int>{stoi(tokens[L])};
            vector<int> res;
            int mid = L + 1;
            while (mid < R)
            {
                string op = tokens[mid];
                vector<int> left_res = f (L, mid - 1);
                vector<int> right_res = f (mid + 1, R);
                for (int l: left_res)
                {
                    for (int r: right_res)
                    {
                        if (op == "+")
                            res.push_back(l + r);
                        else if (op == "-")
                            res.push_back(l - r);
                        else if (op == "*")
                            res.push_back(l * r);
                    }
                }
                mid += 2;
            }
            return res;
        };
        return f(0, tokens.size() - 1);
    };
};
