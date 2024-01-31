class Solution {
public:
    int evalRPN(vector<string>& tokens){
        deque<int>  E;
        int         a, b;

        for (string s: tokens){
            if (s == "+"){
                a = E.front(), E.pop_front();
                b = E.front(), E.pop_front();
                E.push_front(b + a);
            } else if (s == "-"){
                a = E.front(), E.pop_front();
                b = E.front(), E.pop_front();
                E.push_front(b - a);
            } else if (s == "*"){
                a = E.front(), E.pop_front();
                b = E.front(), E.pop_front();
                E.push_front(b * a);
            } else if (s == "/"){
                a = E.front(), E.pop_front();
                b = E.front(), E.pop_front();
                E.push_front(b / a);
            } else  E.push_front(stoi(s));
        }
        return E.front() ;
    }
};
