class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int>  E;
        int         a, b;

        for (string t: tokens)
        {
            if (t == "+")
            {
                a = E.top();
                E.pop();
                b = E.top();
                E.pop();
                E.push(b + a);
            }
            else if (t == "-")
            {
                a = E.top();
                E.pop();
                b = E.top();
                E.pop();
                E.push(b - a);
            }
            else if (t == "*")
            {
                a = E.top();
                E.pop();
                b = E.top();
                E.pop();
                E.push(b * a);
            }
            else if (t == "/")
            {
                a = E.top();
                E.pop();
                b = E.top();
                E.pop();
                E.push(b / a);
            }
            else    E.push(stoi(t));
        }
        return E.top() ;
    }
};
