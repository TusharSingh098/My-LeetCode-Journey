class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    
        int num{x};
        int rev{0};
        while (x > 0)
        {
            int lst_dig{x % 10};
            x /= 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && lst_dig > 7)) return false;

            rev = rev * 10 + lst_dig;
            
        }
        return rev == num;
    }
};
