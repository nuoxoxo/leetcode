type RandomizedSet struct {

    S map[int]bool
}


func Constructor() RandomizedSet {

    S := make (map[int]bool)
    return RandomizedSet { S }
}


func (this *RandomizedSet) Insert(val int) bool {

    exist, ok := this.S [val]
    if ok && exist {
        return false
    }
    this.S [val] = true
    return true
}


func (this *RandomizedSet) Remove(val int) bool {

    exist, ok := this.S [val]
    if ! ok || ! exist {
        return false
    }
    this.S [val] = false
    return true
}


func (this *RandomizedSet) GetRandom() int {

    arr := []int{}
    for k, v := range this.S {
        if v {
            arr = append(arr, k)
        }
    }
    choice := len(arr)
    if choice != 0 {
        return arr[rand.Intn( len(arr) )]
    }
    return arr[ choice ]
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
