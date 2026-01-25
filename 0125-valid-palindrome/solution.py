class Solution:
    def isPalindrome(self, s: str) -> bool:
        #Remove non-alphanumeric characters
        filteredText = ''.join(filter(str.isalnum, s))

        #Convert all characters to lowercase
        lowerText = filteredText.lower()

        if lowerText == lowerText[::-1]:
            return True
        else:
            return False
