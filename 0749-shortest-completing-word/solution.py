class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        freq = Counter(i.lower() for i in licensePlate if i.isalpha())
        completing_words = []
        for i in words:
            for j in freq:
                if (freq[j] > i.count(j)):
                    break
            else:
                completing_words.append(i)
        return min(completing_words, key=len, default="")

