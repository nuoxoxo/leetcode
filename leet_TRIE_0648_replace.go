type TrieNode struct {
    edges map[rune] * TrieNode
    isend bool
}

type Trie struct {
    root * TrieNode
}

func NewTrieNode() * TrieNode {

    return & TrieNode {
        edges: make(map[rune] * TrieNode),
        isend: false,
    }
}

func NewTrie( dict []string ) * Trie {

    res := & Trie {root : NewTrieNode()}
    for _, word := range dict {
        res.Insert(word)
    }
    return res
}

func (trie * Trie) Insert (word string) {

    node := trie.root
    for _, run := range word {
        if _, hasKey := node.edges[run]; ! hasKey {
            node.edges[run] = NewTrieNode()
        }
        node = node.edges[run]
    }
    node.isend = true
}

func (trie * Trie) Find (word string) string {

    // res := strings.Builder{}
    var res string
    node := trie.root
    for _, run := range word {
        if _, hasKey := node.edges[run]; ! hasKey {
            break
        }
        // res.WriteRune(run)
        res += string(run)
        node = node.edges[run]
        if node.isend {
            // return res.String()
            return res
        }
    }
    return word
    
}

func Trie_solution(dict/*ionary*/ []string, sentence string) string {

    var res string
    words := strings.Split(sentence, " ")
    trie := NewTrie(dict)
    for _, word := range words {
        res += " " + trie.Find(word)
    }
    return res[1:]
}

func replaceWords(dictionary []string, sentence string) string {

    solutions := []func([]string, string) string {
        Trie_solution,
    }
    return solutions[0](dictionary, sentence)
}


