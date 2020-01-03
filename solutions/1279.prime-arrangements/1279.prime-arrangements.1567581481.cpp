class Solution {
public:
    int numPrimeArrangements(int n) {
        if (n < 2) {
            return 1;
        }
        int primes = countPrimes(n);
        int noPrimes = n - primes;
        return (int) mul(fact(primes), fact(noPrimes));
    }
    
    int countPrimes(int n) {
        if (n < 2) {
            return 0;
        }
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int j = 2; j <= sqrt(n); j++) {
            if (!isPrime[j]) {
                continue;
            }
            for (int k = j * j; k <= n; k += j) {
                isPrime[k] = false;
            }
        }
        
        int count = 0;
        for (int j = 2; j <= n; j++) {
            if (isPrime[j]) {
                count++;
            }
        }
        return count;
    }
    
    long long fact(int x) {
        long long res = 1;
        for (int i = 1; i <= x; i++) {
            res = mul(res, i);
        }
        return res;
    }
    
    long long mul(long long a, long long b) {
        return (a * b) % mod;
    }
    
private:
    long long mod = 1e9 + 7;
};
