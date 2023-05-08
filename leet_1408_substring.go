func stringMatching(words []string) []string {
    r := []string {}
    for _, sub := range words {
        for _, w := range words {
            if sub != w && strings.Contains(w, sub) {
                r = append(r, sub)
            }
        }
    }
    return r
}
