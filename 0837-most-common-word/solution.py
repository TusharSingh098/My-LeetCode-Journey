class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = ""
        symbols = set("!?',;.")
        for i in paragraph:
            if (i not in symbols):
                if (i.isalpha()):
                    words += i.lower()
                else:
                    words += i
            else:
                words += " "
        
        banned_set = set(banned)
        words = words.split()

        counts = collections.Counter(word for word in words if word not in banned_set)
        return max(counts.keys(), key=counts.get)
