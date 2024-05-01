func reversePrefix(word string, ch byte) string {

    solutions := []func(word string, ch byte) string {
        // using_string,
        using_byte_slice,
    }
    return solutions[0](word, ch)
}

func using_byte_slice(word string, ch byte) string {

    index := -1
    N := len(word)
    for i, c := range word {
        if byte(c) == ch {
            index = i
            break
        }
    }
    if index < 0 {
        return word
    }

    // reverse substring using []byte
    arr := make([]byte, N)
    i := index
    for index > -1 {
        arr[i - index] = word[index]
        index--
    }
    i++
    for i < N {
        arr[i] = word[i]
        i++
    }
    return string(arr)
}

func using_string(word string, ch byte) string {

    index := -1
    N := len(word)
    for i, c := range word {
        if byte(c) == ch {
            index = i
            break
        }
    }
    if index < 0 {
        return word
    }
    res := ""
    i := index + 1
    for index > -1 {
        res += string(word[index])
        index--
    }
    // fmt.Println(res)
    for i < N {
        res += string(word[i])
        i++
    }
    return res
}
