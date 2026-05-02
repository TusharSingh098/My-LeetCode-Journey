#include <climits>
class Solution {
public:
    int reverse(int x) {
        int rev{};
        while (x != 0)
        {
            int lst_dig{x % 10};
            x /= 10;

            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && lst_dig > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && lst_dig < -8)) return 0;

            rev = rev * 10 + lst_dig;            
        }
        return rev;
    }
};
