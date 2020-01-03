// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return find(1, n);
    }

    int find(int lo, int hi) {
        if (lo == hi) {
            return lo;
        }
        int mid = lo + (hi - lo) / 2;
        if (isBadVersion(mid)) {
            return find(lo, mid);
        } else {
            return find(mid+1, hi);
        }
    }
    
};
