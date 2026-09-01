class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        double y = 0;
        int temp = x;
        while (x > 0) {
            int last = x % 10;
            y = y * 10 + last;
            x = x / 10;
        }
        return (temp == y);
    }
};