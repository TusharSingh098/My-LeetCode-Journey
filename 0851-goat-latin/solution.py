class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        res = ""
        words = sentence.split()
        vowels = set("aeiouAEIOU")
        
        if (words[0][0] in vowels):
            res += words[0] + "ma" + "a"
        else:
            res += words[0][1:] + words[0][0] + "ma" + "a"

        n = 2

        for i in words[1:]:
            word = None
            if (i[0] in vowels):
                word = " " + i + "ma" + "a" * n
            else:
                word = " " + i[1:] + i[0] + "ma" + "a" * n
            res += word
            n += 1

        return res
