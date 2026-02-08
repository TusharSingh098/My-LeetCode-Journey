class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        codes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        alphabet = "abcdefghijklmnopqrstuvwxyz"
        decrypt = {alphabet[i]: codes[i] for i in range(26)}
        res = []
        for word in words:
            encrypt = ""
            for char in word:
                encrypt += decrypt[char]
            res.append(encrypt)
        return len(set(res))
