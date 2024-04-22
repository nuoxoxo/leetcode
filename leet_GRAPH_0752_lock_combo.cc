class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        vector<int(*)(vector<string> &, string)> Solutions {
            BFS,
        };
        return Solutions[0](deadends, target);
    }

    static int BFS(vector<string>& deadends, string target) {

        set<string> nogo (deadends.begin(), deadends.end());
        string code = "0000";

        if (nogo.find(target) != nogo.end())
            return -1;
        if (nogo.find(code) != nogo.end())
            return -1;

        deque<string> Q {code};
        unordered_map<string, int> steps;

        while (!Q.empty()) {
            code = Q.front();
            Q.pop_front();
            if (code == target) {
                return steps[code];
            }
            int i = -1;
            while (++i < 4) {
                int n = code[i] - '0';
                for (int offset: {-1, 1}) {
                    char digit = (char) (((n + offset + 10) % 10) + '0');
                    string _new = code;
                    _new[i] = digit; // string is mutable in cpp
                    if (_new == target)
                        return steps[code] + 1;
                    if (nogo.find(_new) != nogo.end() || steps.find(_new) != steps.end())
                        continue ;
                    steps[_new] = steps[code] + 1;
                    Q.push_back(_new);
                }
            }
        }
        return -1;
    }
};
