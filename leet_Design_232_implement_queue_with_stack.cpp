/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class MyQueue {

private:
    stack<int>  S;

public:
    MyQueue() {
    }
    
    void push(int x) {
        stack<int>  T;
        while (!S.empty())
        {
            T.push(S.top());
            S.pop();
        }
        S.push(x);
        while (!T.empty())
        {
            S.push(T.top());
            T.pop();
        }
    }
    
    int pop() {
        int n = S.top();
        S.pop();
        return (n);
    }
    
    int peek() {
        return S.top();
    }
    
    bool empty() {
        return (S.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
