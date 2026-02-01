def count_chars(s: str) -> dict:
    counts = {}
    for i in s:
        if i not in counts:
            counts[i] = 1
        else:
            counts[i] += 1
    return counts

class Solution:
    def longestPalindrome(self, s: str) -> int:
        length = len(s)
        if (length == 1):
            return 1
        
        char_count = count_chars(s)

        palin_len = 0
        center = 0
        for i in char_count:
            if (char_count[i] % 2 == 0):
                palin_len += char_count[i]
            elif (char_count[i] > 1):
                palin_len += char_count[i] - 1
                if (center == 0):
                    center = 1
                    palin_len += 1
            elif (center == 0):
                center = 1
                palin_len += 1
        return palin_len
            
