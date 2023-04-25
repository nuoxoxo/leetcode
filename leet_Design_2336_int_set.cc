class SmallestInfiniteSet {
public:
    bool v[1001];
    SmallestInfiniteSet() {
        int i = 0;
        while (++i < 1001)
            v[i] = 1;
    }
    
    int popSmallest() {
        int i = 0;
        while( ! v[++i])
        {
            ;;
        }
        v[i] = 0;
        return i;
        
    }
    
    void addBack(int num) {
        v[num] = 1;
    }
};;

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
