class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        return [
            # index_method, # Slow
            linear_pass,
        ][0](word, ch)

def linear_pass(word: str, ch: str) -> str:
    for i in range(len(word)):
        if word[i] == ch:
            return word[i::-1] + word[i + 1:]
    return word

def index_method(word:str, ch:str) -> str:
    if ch in word:
        idx = word.index(ch)
        return word[idx::-1] + word[idx + 1:]
    return word
