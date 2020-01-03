class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int d = 0;
        res.push_back(d);
        for (int i = 1; ; i++) {
            int z = zeros(i);
            if (z == n) {
                break;
            }
            // Flip the z-th bit
            d ^= 1 << z;
            res.push_back(d);
        }
        return res;
    }
    
    int zeros(int i) {
        int c = 0;
        while ((i & 0x1) == 0) {
            c++;
            i >>= 1;
        }
        return c;
    }
};
