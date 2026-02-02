class Solution:
    def reverseWords(self, s: str) -> str:
        word_lst = s.split()
        for i in range(len(word_lst)):
            word_lst[i] = word_lst[i][::-1]
        return " ".join(word_lst)
