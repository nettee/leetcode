class Solution {
public:
    vector<int> countBits(int num) {
        int w = width(num);
        int val = 0;
        int ttl = num;
        vector<int> res;
        backtrack(res, val, w-1, ttl, 0);
        return res;
    }
    
    void backtrack(vector<int>& res, int& val, int k, int& ttl, int ones) {
        if (ttl < 0) {
            return;
        }
        if (k < 0) {
            res.push_back(ones);
            ttl--;
            return;
        }
        // set k-th bit to 0
        val &= ~(1 << k);
        backtrack(res, val, k-1, ttl, ones);
        // set k-th bit to 1
        val |= 1 << k;
        backtrack(res, val, k-1, ttl, ones+1);
    }
    
    int width(int num) {
        int k = 0;
        while (num != 0) {
            num >>= 1;
            k++;
        }
        return k;
    }
};
