class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        n = len(word)
        if n <= 1:
            return True

        case1 = case2 = True
        case3 = True if (word[0] >= "A" and word[0] <= "Z") else False

        for i in range(n):
            is_cap = "A" <= word[i] <= "Z"

            if not is_cap:
                case1 = False
            if is_cap:
                case2 = False
            if (i != 0) and is_cap:
                case3 = False

        return case1 or case2 or case3
            
