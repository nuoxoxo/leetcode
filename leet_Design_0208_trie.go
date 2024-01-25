type TrieNode struct {
    ended bool
    branch [26] * TrieNode
}

type Trie struct {
    node * TrieNode
}


func Constructor() Trie {
    return Trie {
        node: & TrieNode {},
    }
}


func (this *Trie) Insert(word string)  {
    cur := this.node
    for _, c := range word {
        if cur.branch[c - 'a'] == nil {
            cur.branch[c - 'a'] = & TrieNode {}
        }
        cur = cur.branch[c - 'a']
    }
    cur.ended = true
}


func (this *Trie) Search(word string) bool {
    cur := this.node
    for _, c := range word {
        if cur.branch[c - 'a'] == nil {
            return false
        }
        cur = cur.branch[c - 'a']
    }
    return cur.ended 
}


func (this *Trie) StartsWith(prefix string) bool {
    cur := this.node
    for _, c := range prefix {
        if cur.branch[c - 'a'] == nil {
            return false
        }
        cur = cur.branch[c - 'a']
    }
    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
