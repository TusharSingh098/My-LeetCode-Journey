class Solution:
    def validPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        
        while (left < right):
            if (s[left] != s[right]):
                opt1 = s[left + 1 : right + 1]
                opt2 = s[left : right]
                
                return (opt1 == opt1[::-1]) or (opt2 == opt2[::-1])
            
            left += 1
            right -= 1
            
        return True

