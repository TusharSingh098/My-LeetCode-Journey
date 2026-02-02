class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        char_lst = list(s)
        length = len(char_lst)
        for i in range(0, length, 2 * k):
            char_lst[i: i + k] = char_lst[i: i + k][::-1]
        return "".join(char_lst)
