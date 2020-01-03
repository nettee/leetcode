class Solution {
public:
    int countPrimes(int n) {
        // Filter method
        bool* a = new bool[n];
        for (int i = 2; i < n; i++) {
            a[i] = true;
        }
        for (int k = 2; k <= n / 2; k++) {
            if (!a[k]) {
                continue; // We only filter with primes
            }
            int m = 2 * k;
            while (m < n) {
                a[m] = false;
                m += k;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (a[i]) {
                count++;
            }
        }
        return count;
    }
};
