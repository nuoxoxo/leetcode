func removeSubfolders(folder []string) []string {
    sort.Strings(folder)
    res := []string{folder[0]}
    for i := range(folder) {
        if i == 0 {continue}
        parent := res[len(res) - 1] + "/"
        bound := len(parent)
        if bound > len(folder[i]) {
            bound = len(folder[i])
            }
        substr := folder[i][:bound]
        if parent != substr {
            res = append(res, folder[i])
        }
        // fmt.Println(parent, substr, res)
    }
    return res
}
