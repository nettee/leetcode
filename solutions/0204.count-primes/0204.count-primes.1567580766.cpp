class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        
        for (int j = 2; j < sqrt(n); j++) {
            if (!isPrime[j]) {
                continue;
            }
            // filter out j's multiple
            for (int k = j * j; k < n; k += j) {
                isPrime[k] = false;
            }
        }
        
        int count = 0;
        for (int j = 2; j < n; j++) {
            if (isPrime[j]) {
                count++;
            }
        }
        return count;
    }
};
