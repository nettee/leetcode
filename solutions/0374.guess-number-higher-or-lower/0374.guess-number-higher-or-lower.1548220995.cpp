// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return guessit(1, n);
    }
    
    int guessit(int lo, int hi) {
        if (lo == hi) {
            return lo;
        }
        int mid = lo + (hi - lo) / 2;
        int r = guess(mid);
        if (r == 1) {
            return guessit(mid + 1, hi);
        } else if (r == -1) {
            return guessit(lo, mid - 1);
        } else {
            return mid;
        }
    }
};
