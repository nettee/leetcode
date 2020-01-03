class Solution {
public:
    int countPrimes(int n) {
        // Filter method
        bool* a = new bool[n];
        for (int i = 2; i < n; i++) {
            a[i] = true;
        }
        int count = 0;
        for (int k = 2; k < n; k++) {
            if (a[k]) {
                count++; // Not filtered by its previous numbers
            } else {
                continue; // We only filter by primes
            }
            // Filter out all numbers that k can divide
            for (int m = 2 * k; m < n; m += k) {
                a[m] = false;
            }
        }
        return count;
    }
};
