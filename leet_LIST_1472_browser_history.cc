class BrowserHistory {

class Node { // DIY node class

    public:

    string  URL;
    Node    * prev;
    Node    * next;

    Node (string url)
    {
        this->URL = url;
        prev = NULL;
        next = NULL;
    }
};

public:

    Node * Curr;

    BrowserHistory(string homepage) {

        this->Curr = new Node (homepage);
    }
    
    void visit(string url) {

        // clears up all the forward history
        //  1. create a next - set next's prev to curr
        //  2. move to the next
        //  (returns nothing)

        Node * _nxt = new Node (url);
        _nxt->prev = this->Curr;
        this->Curr->next = _nxt;
        this->Curr = this->Curr->next;
    }
    
    string back(int steps) {
        
        // can only go back (x < steps) steps in the history
        //  - move to min(steps back, list head)
        //  - returns a URL

        while (this->Curr->prev && steps)
        {
            this->Curr = this->Curr->prev;
            --steps;
        }
        return this->Curr->URL;
    }
    
    string forward(int steps) {

        // can only Forward (x < steps) steps in the history
        //  - move to min(steps ahead, list tail)
        //  - returns a URL

        while (this->Curr->next && steps)
        {
            this->Curr = this->Curr->next;
            --steps;
        }
        return this->Curr->URL;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

