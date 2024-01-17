type RandomizedSet struct {
    getindexbyvalue map[int]int
    arr []int
}


func Constructor() RandomizedSet {
    getindexbyvalue := make (map[int]int)
    arr := make ([]int, 0)
    return RandomizedSet { getindexbyvalue, arr }
}


func (this *RandomizedSet) Insert(val int) bool {
    _, ok := this.getindexbyvalue[ val ]
    if ok {
        return false
    }
    this.arr = append( this.arr, val )
    this.getindexbyvalue[ val ] = len(this.arr) - 1
    return true
}


func (this *RandomizedSet) Remove(val int) bool {
    index, ok := this.getindexbyvalue[ val ]
    if !ok {
        return false
    }
    
    this.arr[ index ] = this.arr[ len(this.arr) - 1 ] // arr[index] repl. by the last element
    this.getindexbyvalue[ this.arr[ index ] ] = index
    delete ( this.getindexbyvalue, val ) // del. that key in dict
    this.arr = this.arr[:len(this.arr) - 1] // pop
    return true
}


func (this *RandomizedSet) GetRandom() int {
    choice := len(this.arr)
    if choice != 0 {
        return this.arr[rand.Intn( len(this.arr) )]
    }
    return this.arr[ choice ]
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
